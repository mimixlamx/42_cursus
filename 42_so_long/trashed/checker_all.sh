#!/bin/bash

BIN=./so_long

if [ ! -x "$BIN" ]; then
	echo "Erreur: $BIN introuvable ou non exécutable"
	exit 1
fi

echo "========== VALID MAPS =========="
for map in test_maps/valid/*.ber; do
	echo
	echo "----- $(basename "$map") -----"
	"$BIN" "$map"
	echo "Code retour: $?"
done

echo
echo "========== INVALID MAPS =========="
for map in test_maps/invalid/*.ber; do
	echo
	echo "----- $(basename "$map") -----"
	"$BIN" "$map"
	echo "Code retour: $?"
done
