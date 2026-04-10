#!/bin/bash
BIN=./so_long
MAP_DIR=./test_maps

if [ ! -x "$BIN" ]; then
	echo "Erreur: $BIN introuvable ou non exécutable"
	exit 1
fi

if [ ! -d "$MAP_DIR" ]; then
	echo "Erreur: dossier $MAP_DIR introuvable"
	exit 1
fi

echo "========== CHECKER so_long =========="
for map in "$MAP_DIR"/*.ber; do
	echo
	echo "----- Test: $(basename "$map") -----"
	"$BIN" "$map"
	echo "Code retour: $?"
done
echo
echo "========== FIN =========="
