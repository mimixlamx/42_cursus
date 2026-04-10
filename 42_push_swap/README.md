*This project has been created as part of the 42 curriculum by mbruyere.*

# Push_swap

## Description

Push_swap is an algorithmic project whose goal is to sort a list of integers using a limited set of instructions and two stacks (A and B).

The program receives a sequence of integers as input and must output the smallest possible number of operations to sort stack A in ascending order.

Only a specific set of operations is allowed (swap, push, rotate, reverse rotate), making this project focused on algorithm optimization and efficiency.

This implementation uses a cost-based strategy (inspired by the Turk algorithm), where each possible move is evaluated using:
- cost_a: position in stack A
- cost_b: position in stack B
- total_cost: optimized move cost

The algorithm always selects the cheapest move to minimize the total number of operations.

## Instructions

### Compilation
make

### Execution
./push_swap 3 2 1
./push_swap "3 2 1"

### Verification
./push_swap 3 2 1 | ./checker_linux 3 2 1

### Cleaning
make clean
make fclean
make re

## Resources

### Documentation
- Official 42 push_swap subject
- C standard library documentation

### Learning Resources
- Algorithm optimization concepts
- Stack-based sorting strategies
- Complexity analysis

### AI Usage
AI was used to:
- Help understand and refine the Turk algorithm approach
- Assist in writing and structuring the Makefile according to project requirements

The core algorithm and overall project logic were designed and implemented manually.

## Features

- Full input validation (duplicates, overflow, invalid values)
- Handles both multiple arguments and string input
- Optimized sorting for small and large datasets
- Uses combined rotations (rr, rrr)

## Author

- mbruyere
