#!/bin/bash

BIN=./so_long
MAP_DIR=maps/invalid_maps
TOTAL=0
FAIL=0

if [ ! -x "$BIN" ]; then
	echo "❌ so_long introuvable ou non exécutable"
	exit 1
fi

if [ ! -d "$MAP_DIR" ]; then
	echo "❌ Dossier $MAP_DIR introuvable"
	exit 1
fi

echo "=== Test des maps invalides avec Valgrind ==="
echo

for map in "$MAP_DIR"/*.ber; do
	((TOTAL++))
	echo "▶ Testing: $map"
	echo

	valgrind --leak-check=full \
	         --errors-for-leak-kinds=all \
	         --track-origins=yes \
	         --error-exitcode=42 \
	         $BIN "$map"

	if [ $? -eq 42 ]; then
		echo
		echo "❌ Leak ou still reachable détecté"
		((FAIL++))
	else
		echo
		echo "✅ OK (aucun leak, aucun still reachable)"
	fi

	echo "------------------------------------------"
	echo
done

# ✅ Confirmation finale
if [ $FAIL -eq 0 ]; then
	echo "🎉 TOUS LES TESTS SONT PASSÉS : aucun leak, aucun still reachable ✅"
else
	echo "⚠️ $FAIL / $TOTAL tests ont échoué (leak ou still reachable)"
fi
