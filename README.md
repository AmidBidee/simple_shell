# [C - Simple Shell](https://github.com/AmidBidee/simple_shell/)

A simple unix command interpreter built as a project for the ALX software engineering program.

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone:


	Who designed and implemented the original Unix operating system
	Who wrote the first version of the UNIX shell
	Who invented the B programming language (the direct predecessor to the C programming language)
	Who is Ken Thompson
	How does a shell work
	What is a pid and a ppid
	How to manipulate the environment of the current process
	What is the difference between a function and a system call
	How to create processes
	What are the three prototypes of main
	How does the shell use the PATH to find the programs
	How to execute another program with the execve system call
	How to suspend the execution of a process until one of its children terminates
	What is EOF / “end-of-file”?

### Code will be compiled this way:

	$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89

### Allowed system calls and functions

> **Functions:** closedir, exit, fflush, free, getcwd, getline, isatty, malloc, 
		opendir, readdir

> **System calls:** access, chdir, close, execve, _exit, fork, getpid, kill, open
		read, signal, stat (__xstat), lstat (__lxstat), fstat (__fxstat),
		wait, waitpid, wait3, wait4, write

### Output

	Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
	The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

### Testing

	> Your shell should work like this in interactive mode:

		$ ./hsh
		($) /bin/ls
		hsh main.c shell.c
		($)
		($) exit
		$

	> But also in non-interactive mode:

		$ echo "/bin/ls" | ./hsh
		hsh main.c shell.c test_ls_2
		$
		$ cat test_ls_2
		/bin/ls
		/bin/ls
		$
		$ cat test_ls_2 | ./hsh
		hsh main.c shell.c test_ls_2
		hsh main.c shell.c test_ls_2
		$
	
