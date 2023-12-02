This is the simple shell ALX project repository

Introduction:
This projects seeks to show understanding of how a shell/wrap arond coding environment works. It will work similary to the sh(Bourne Shell) created by Stephen Bourne using a limited number of simple standard library functrions and custom functions I created in the alx-low_level_proggramming repo.


Usage:

In order to use this program clone the repo from https://github.com/Nano2211/simple_shell

It will be compiled with : gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
in that same directory.

How its used:
First run the program using $ ./hsh which will then parse a simple prompt and wait for a simple command of type $ command.
This shell will be able to handle 2 commands , builtins and normal programs.

List of built ins:
exit [exitstatus]
Exit from the program with exitstatus value.

getenv NAME

cd [directory]
Switch to the specified directory (path).

env
Return the value of the NAME variable if it is in the environment

help [command]
Displays the syntax for the command, or all commands.

history
Displays the last typed user .

echo [$$] or [$?] or [$PATH] Return pid and exit statue and PATH.

List of commands:

Basically Every Program in $PATH It Support Single Word like ls

It Handle Path ls /tmp

it Handle Options Like ls -l

it Handle All Three Togther Like ls -l /var 

it Handle Command Path Also Like /bin/ls And All The Option And Path Like /bin/ls -l /var

it Handles Comments #

Lists of functions and system calls allowed:

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
fstat (man 2 fstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
lstat (man 2 lstat)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (man 2 stat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)