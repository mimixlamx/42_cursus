#!/usr/bin/env bash
set -u

NAME_PUSH="./push_swap"
NAME_CHECKER="./checker"
TMP_DIR=".ps_checker_tmp"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --error-exitcode=99 -q"

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
BLUE="\033[0;34m"
NC="\033[0m"

PASS_COUNT=0
FAIL_COUNT=0

pass() { printf "${GREEN}[OK]${NC} %s\n" "$1"; PASS_COUNT=$((PASS_COUNT + 1)); }
fail() { printf "${RED}[KO]${NC} %s\n" "$1"; FAIL_COUNT=$((FAIL_COUNT + 1)); }
info() { printf "${BLUE}[..]${NC} %s\n" "$1"; }
warn() { printf "${YELLOW}[!!]${NC} %s\n" "$1"; }

cleanup() {
	rm -rf "$TMP_DIR"
}
trap cleanup EXIT

mkdir -p "$TMP_DIR"

run_cmd() {
	local outfile="$1"
	local errfile="$2"
	shift 2
	"$@" >"$outfile" 2>"$errfile"
	return $?
}

run_valgrind_cmd() {
	local outfile="$1"
	local errfile="$2"
	shift 2
	$VALGRIND "$@" >"$outfile" 2>"$errfile"
	return $?
}

gen_args() {
	local count="$1"
	python3 - "$count" <<'PY'
import random, sys
n = int(sys.argv[1])
arr = random.sample(range(-100000, 100000), n)
print(" ".join(map(str, arr)))
PY
}

check_make() {
	info "Compilation"
	if make re >/dev/null 2>&1; then
		pass "make re"
	else
		fail "make re"
		return 1
	fi

	if [ -x "$NAME_PUSH" ]; then
		pass "binary push_swap present"
	else
		fail "binary push_swap absent"
	fi

	if make bonus >/dev/null 2>&1; then
		if [ -x "$NAME_CHECKER" ]; then
			pass "binary checker present"
		else
			fail "binary checker absent after make bonus"
		fi
	else
		warn "make bonus failed or no bonus rule"
	fi
}

check_no_arg() {
	local out="$TMP_DIR/noarg.out"
	local err="$TMP_DIR/noarg.err"

	run_cmd "$out" "$err" "$NAME_PUSH"
	if [ ! -s "$out" ] && [ ! -s "$err" ]; then
		pass "no-arg push_swap prints nothing"
	else
		fail "no-arg push_swap should print nothing"
	fi

	run_valgrind_cmd "$out" "$err" "$NAME_PUSH"
	if [ $? -eq 99 ]; then
		fail "valgrind no-arg push_swap"
	else
		pass "valgrind no-arg push_swap"
	fi
}

check_error_case() {
	local label="$1"
	shift
	local out="$TMP_DIR/error_${label}.out"
	local err="$TMP_DIR/error_${label}.err"

	run_cmd "$out" "$err" "$NAME_PUSH" "$@"

	if [ ! -s "$out" ] && grep -qx "Error" "$err"; then
		pass "push_swap error stderr: $label"
	else
		fail "push_swap error stderr: $label"
		printf "  args: %s\n" "$*"
		printf "  stdout: [%s]\n" "$(cat "$out" 2>/dev/null)"
		printf "  stderr: [%s]\n" "$(cat "$err" 2>/dev/null)"
	fi

	run_valgrind_cmd "$out" "$err" "$NAME_PUSH" "$@"
	if [ $? -eq 99 ]; then
		fail "valgrind push_swap error case: $label"
	else
		pass "valgrind push_swap error case: $label"
	fi
}

check_checker_error_case() {
	local label="$1"
	shift
	local out="$TMP_DIR/checker_error_${label}.out"
	local err="$TMP_DIR/checker_error_${label}.err"

	printf 'badop\n' | "$NAME_CHECKER" "$@" >"$out" 2>"$err"
	if [ ! -s "$out" ] && grep -qx "Error" "$err"; then
		pass "checker invalid instruction stderr: $label"
	else
		fail "checker invalid instruction stderr: $label"
	fi

	printf 'badop\n' | $VALGRIND "$NAME_CHECKER" "$@" >"$out" 2>"$err"
	if [ $? -eq 99 ]; then
		fail "valgrind checker invalid instruction: $label"
	else
		pass "valgrind checker invalid instruction: $label"
	fi
}

check_sorted_case() {
	local label="$1"
	shift
	local args=("$@")
	local out="$TMP_DIR/sorted_${label}.out"
	local err="$TMP_DIR/sorted_${label}.err"
	local c_out="$TMP_DIR/sorted_${label}.checker.out"
	local c_err="$TMP_DIR/sorted_${label}.checker.err"

	run_cmd "$out" "$err" "$NAME_PUSH" "${args[@]}"
	if [ ! -s "$err" ]; then
		pass "push_swap runs: $label"
	else
		fail "push_swap stderr non-empty: $label"
	fi

	if [ -x "$NAME_CHECKER" ]; then
		"$NAME_PUSH" "${args[@]}" | "$NAME_CHECKER" "${args[@]}" >"$c_out" 2>"$c_err"
		if grep -qx "OK" "$c_out" && [ ! -s "$c_err" ]; then
			pass "sorted by checker: $label"
		else
			fail "sorted by checker: $label"
		fi
	fi

	run_valgrind_cmd "$out" "$err" "$NAME_PUSH" "${args[@]}"
	if [ $? -eq 99 ]; then
		fail "valgrind push_swap: $label"
	else
		pass "valgrind push_swap: $label"
	fi

	if [ -x "$NAME_CHECKER" ]; then
		"$NAME_PUSH" "${args[@]}" >"$TMP_DIR/ops.txt"
		run_valgrind_cmd "$c_out" "$c_err" "$NAME_CHECKER" "${args[@]}" <"$TMP_DIR/ops.txt"
		if [ $? -eq 99 ]; then
			fail "valgrind checker: $label"
		else
			pass "valgrind checker: $label"
		fi
	fi
}

check_random_batch() {
	local size="$1"
	local loops="$2"
	local limit="$3"
	local i=1
	local max_ops=0
	local avg_ops=0
	local total_ops=0

	info "Random batch size=$size loops=$loops limit=$limit"

	while [ "$i" -le "$loops" ]; do
		local args
		args="$(gen_args "$size")"
		local c_out="$TMP_DIR/random_${size}_${i}.checker.out"
		local c_err="$TMP_DIR/random_${size}_${i}.checker.err"
		local op_file="$TMP_DIR/random_${size}_${i}.ops"

		# shellcheck disable=SC2086
		"$NAME_PUSH" $args >"$op_file" 2>"$TMP_DIR/random_${size}_${i}.push.err"
		local ops
		ops="$(wc -l <"$op_file" | tr -d ' ')"
		total_ops=$((total_ops + ops))
		[ "$ops" -gt "$max_ops" ] && max_ops="$ops"

		# shellcheck disable=SC2086
		"$NAME_CHECKER" $args <"$op_file" >"$c_out" 2>"$c_err"
		if ! grep -qx "OK" "$c_out"; then
			fail "random sort KO size=$size iteration=$i"
			printf "  args: %s\n" "$args"
			return 1
		fi

		# shellcheck disable=SC2086
		$VALGRIND "$NAME_PUSH" $args >/dev/null 2>"$TMP_DIR/vg_push_${size}_${i}.err"
		if [ $? -eq 99 ]; then
			fail "valgrind push_swap random size=$size iteration=$i"
			return 1
		fi

		# shellcheck disable=SC2086
		$VALGRIND "$NAME_CHECKER" $args <"$op_file" >/dev/null 2>"$TMP_DIR/vg_checker_${size}_${i}.err"
		if [ $? -eq 99 ]; then
			fail "valgrind checker random size=$size iteration=$i"
			return 1
		fi

		if [ "$limit" -gt 0 ] && [ "$ops" -gt "$limit" ]; then
			fail "too many ops size=$size iteration=$i -> $ops > $limit"
		fi

		i=$((i + 1))
	done

	avg_ops=$((total_ops / loops))
	pass "random batch validated size=$size avg=$avg_ops max=$max_ops"
}

check_manual_checker() {
	if [ ! -x "$NAME_CHECKER" ]; then
		warn "checker not found, skipped checker-specific tests"
		return
	fi

	local out="$TMP_DIR/manual_checker.out"
	local err="$TMP_DIR/manual_checker.err"

	printf "sa\nrra\npb\n" | "$NAME_CHECKER" 3 2 1 0 >"$out" 2>"$err"
	if grep -qx "KO" "$out"; then
		pass "checker detects KO"
	else
		fail "checker detects KO"
	fi

	printf "rra\npb\nsa\nrra\npa\n" | "$NAME_CHECKER" 3 2 1 0 >"$out" 2>"$err"
	if grep -qx "OK" "$out"; then
		pass "checker detects OK"
	else
		fail "checker detects OK"
	fi

	printf "rra\npb\nsa\nrra\npa\n" | $VALGRIND "$NAME_CHECKER" 3 2 1 0 >"$out" 2>"$err"
	if [ $? -eq 99 ]; then
		fail "valgrind checker manual OK case"
	else
		pass "valgrind checker manual OK case"
	fi
}

main() {
	check_make || exit 1
	echo

	check_no_arg
	echo

	check_error_case "alpha" 1 a 3
	check_error_case "dup" 1 2 2 3
	check_error_case "overflow_pos" 2147483648
	check_error_case "overflow_neg" -2147483649
	check_error_case "empty_string" ""
	check_error_case "plus_only" +
	check_error_case "minus_only" -
	check_error_case "mixed" "1 2" 3
	echo

	check_sorted_case "already_sorted" 1 2 3 4 5
	check_sorted_case "reverse_3" 3 2 1
	check_sorted_case "reverse_5" 5 4 3 2 1
	check_sorted_case "mixed_small" -3 42 0 -1 8
	echo

if [ -x "$NAME_CHECKER" ]; then
    check_manual_checker
    check_checker_error_case "bad_instruction" 3 2 1 0
    echo
    check_random_batch 3 20 3
    check_random_batch 5 20 12
    check_random_batch 10 30 0
    check_random_batch 100 20 700
    check_random_batch 500 5 5500
else
    warn "checker absent: skip bonus/random validation"
fi

	printf "\n${GREEN}PASS:${NC} %d\n" "$PASS_COUNT"
	printf "${RED}FAIL:${NC} %d\n" "$FAIL_COUNT"

	if [ "$FAIL_COUNT" -ne 0 ]; then
		exit 1
	fi
}

main "$@"
