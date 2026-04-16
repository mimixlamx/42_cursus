*This project has been created as part of the 42 curriculum by mbruyere.*

# Pipex

## Description

Pipex is a UNIX system programming project whose goal is to recreate the behavior of pipes in the shell.

The program executes two commands in sequence by redirecting:
- the input from a file
- the output to another file

It must behave exactly like the following shell command:

< file1 cmd1 | cmd2 > file2

This project focuses on understanding low-level system calls and process management, including:
- process creation with fork
- inter-process communication with pipe
- file descriptor redirection with dup2
- program execution with execve
- error handling using errno

The implementation resolves command paths using the PATH environment variable and ensures proper exit codes:
- 127 → command not found
- 126 → permission denied

## Instructions

### Compilation
make

### Execution
./pipex file1 cmd1 cmd2 file2

### Example
./pipex infile "cat -e" "wc -l" outfile

Equivalent shell command:
< infile cat -e | wc -l > outfile

### Cleaning
make clean
make fclean
make re

## Resources

### Documentation
- man fork
- man execve
- man pipe
- man dup2
- man waitpid
- https://man7.org/linux/man-pages/

### Learning Resources
- UNIX process and file descriptor management
- Pipe and redirection behavior in shells
- Error handling with errno

### AI Usage
AI was used as a learning assistant to:
- understand system calls (pipe, fork, dup2, execve)
- generate a propper readme

All logic, structure, and implementation decisions were written and validated manually.

## Features

- Handles command execution with arguments
- Supports absolute and relative paths
- Resolves commands using PATH
- Proper error handling (infile, outfile, commands)
- Correct management of file descriptors
- No memory leaks and no zombie processes

## Author

- mbruyere
