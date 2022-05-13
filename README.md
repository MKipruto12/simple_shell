# simple shell project

-[x]Work in progress
-[]Done


![alt text](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

### Resources
> **Concepts**

>> * [concept1](https://alx-intranet.hbtn.io/concepts/64)
>> * [concept2](https://alx-intranet.hbtn.io/concepts/350)

> **Read or watch**

>> * [unix shell](https://en.wikipedia.org/wiki/Unix_shell)
>> * [Ken_Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
>> * [Thonpson_shell](https://en.wikipedia.org/wiki/Thompson_shell)
>> * **Everything you need to know to start coding your own shell concept page**

 ## Authors
- **Mercy Kipruto** - [mercykipruto2017@gmail.com](https://github.com/MKipruto12)
- **Jumba Mark** - [jumbamark@yahoo.com](https://github.com/jumbamark)

### Requirements

#### General

* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All your files should end with a new line
* A `README.md` file, at the root of the folder of the project is mandatory
* Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be `include` guarded
* Use system calls only when you need to ([why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems))


### Output

> * Unless specified otherwise, your program **must have the exact same output** as `sh` `(/bin/sh)` as well as the exact same error output.
> * The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (See below)

Example of an error with `sh`:

```
$ echo "qwerty" | /bin/sh /bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

Same error with your program `hsh`:

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
#### List of allowed functions and system calls

* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `getpid` (man 2 getpid)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror` (man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__xstat) (man 2 stat)
* `lstat` (__lxstat) (man 2 lstat)
* `fstat` (__fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)

### Compilation

Your shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Testing

Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
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
```

## Tasks

### 0.Betty would be proud

Write a beautiful code that passes the Betty checks

**Repo:**

> * GitHub repository: `simple_shell`

### 1.Simple shell 0.1

Write a UNIX command line interpreter.

> * Usage: simple_shell

Your Shell should:

> * Display a prompt and wait for the user to type a command. A command line always ends with a new line.
> * The prompt is displayed again each time a command has been executed.
> * The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
> * The command lines are made only of one word. No arguments will be passed to programs.
> * If an executable cannot be found, print an error message and display the prompt again.
> * Handle errors.
> * You have to handle the `“end of file”` condition `(Ctrl+D)`

You don’t have to:

> * use the `PATH`
> * implement built-ins
> * handle special characters : ```", ', `, \, *, &, #```
> * be able to move the cursor
> * handle commands with arguments

```
julien@ubuntu:~/shell$ ./shell
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ /bin/ls -l
./shell: No such file or directory
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
#cisfun$ barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ julien@ubuntu:~/shell$
```






