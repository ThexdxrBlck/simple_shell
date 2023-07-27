0x16. C - Simple Shell
C
Group project
Syscall
Project to be done in teams of 2 people (your team: Olebogeng Morobe, Boitumelo Kotane)

TASKS

0. Betty would be proud

Write code that passes the Betty checks

1. Simple shell 0.1

Create a simple UNIX command line interpreter, prompt for user commands, execute them, and display errors. No advanced features, arguments, or special characters are required. Handle "end of file" condition. Execve should be used as the core part of the Shell.

2. Simple shell 0.2

Shell 0.1+ will now handle command lines with arguments

3. Simple shell 0.3

Shell 0.2+ will manage PATH and avoid fork if command doesn't exist

4. Simple shell 0.4

Shell 0.3+ has now added the "exit" built-in for shell termination. Usage: exit (no arguments required)

5. Simple shell 1.0

Shell 0.4+ now includes 'env' built-in to display the current environment

6. Simple shell 0.1.1

For shell 0.1+, Create a custom getline function using a buffer to minimize read system calls. Use static variables, no need to move the cursor. No getline allowed

7. SImple shell 0.2.1

In Shell 0.2+, no trok is allowed

8. Simple shell 0.4.1

Shell 0.4+ now handles built-in 'exit' with the usage: 'exit status', where status is an integer to exit the shell

9. setenv,unstenv

Shell 1.0+ now includes setenv and unsetenv built-in commands. 

setenv allows initializing or modifying environment variables using the syntax: setenv VARIABLE VALUE. It provides error messages on stderr if needed.

unsetenv removes an environment variable using the syntax: unsetenv VARIABLE. It also offers error messages on stderr if needed

10. cd 

Simple shell 1.0+ with the builtin command "cd" which changes the current directory of the process. Syntax: cd [DIRECTORY]. If no argument is given, it defaults to cd $HOME. Handles "cd -" and updates the environment variable PWD. Refer to man chdir and man getcwd

11. ;

Shell 1.0+ supports commands separator ';'

12. && and ||

Shell 1.0+ supports && and || logical operators

13. alias

Introducing Simple Shell 1.0+ with alias built-in command:
Usage: alias [name[='value'] ...]
Prints all aliases in the form name='value'
Prints specific aliases (name, name2, etc.) in the same format
Defines or updates aliases with name='value' pairs

14. Variables

Shell 1.0+ handles variable replacement, $? and $$

15. Comments

Shell 1.0+ with comment handling (#)

16. File as input

Simple shell 1.0 + can run commands from a file given as a command line argument. The file should have one command per line, and the shell won't display a prompt or read from stdin
