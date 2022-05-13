# simple shell project


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
* `stat` (__xstat) (man 2 stat)
* `lstat` (__lxstat) (man 2 lstat)
* `fstat` (__fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)
