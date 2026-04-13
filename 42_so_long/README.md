*This project has been created as part of the 42 curriculum by mbruyere.*

# so_long

## Description

so_long is a simple 2D game developed using the MiniLibX library.

The goal is to navigate a player through a map, collect all collectibles, and reach the exit.

The program reads a map file (.ber), validates its structure, and ensures that the game is playable before launching.

Map validation includes:
- rectangular shape
- closed borders surrounded by walls
- valid characters only (0, 1, P, E, C)
- exactly one player, one exit, and at least one collectible

A flood fill algorithm is used to ensure that all collectibles and the exit are reachable from the player's starting position.

## Instructions

### Compilation
make

### Execution
./so_long maps/map.ber

### Cleaning
make clean  
make fclean  
make re

## Resources

### Documentation
- Official 42 so_long subject
- MiniLibX documentation
- C standard library documentation

### Learning Resources
- Flood fill algorithm
- Event handling with MiniLibX
- Memory management in C

### AI Usage
AI was used to:
- explain the flood fill algorithm
- assist in writing the README file

All core logic (parsing, flood fill, gameplay) was implemented manually.

## Features

- Full map validation before execution
- Flood fill path validation
- Keyboard controls (WASD / arrow keys)
- Move counter displayed in terminal
- Clean exit with proper memory management

## Author

- mbruyere
