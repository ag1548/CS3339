## Program Execution and Performance Evaluation in Linux
CS3339: Computer Architecture

Andres Gonzalez [\<andres.gonzalez@txstate.edu\>](andres.gonzalez@txstate.edu)

Adapted from Apan Qasem's [\<apan@txstate.edu\>](apan@txstate.edu) CS3339 Course

### Description

A simple introduction to command-line program execution and performance evaluation. Covers the following

   * basic Linux commands
   * command-line compilation
     * `gcc` for c programs
     * `g++` for c++ programs
   * performance profiling with `perf`.

Remember that for most commands, there is a page from the manual on how to use it (e.g., `man <command>` such as `man ls`), and there is usually a help menu on the command itself (e.g. `<cmd> --help`, such as `ls --help`). If the help description overflows the size of the window that you currently have for your terminal, you can also pipe the command into the `less` program (a somewhat "successor" to the `more` program, e.g. `ls --help | less`).  To navigate the output of the `less` program, use `j` to "scroll down", use `k` to "scroll up", use `q` to quit, and use `h` for help. There are more navigation shortcuts, these are just a few.  Unfortunately, there is not really a "convenient way to remember" these navigation shortcuts.  Over time spent using the programs, it simply is something of a pattern that you get used to and develop muscle-memory for.  There are also plenty of online resources for learning how to use these tools.

### Outline

- Program Execution and Performance Evaluation in Linux
  - Linux servers
  - Obtaining code samples
  - Building and executing
  - Measuring performance
  - Exploring a new architecture: POWER8
  - Getting performance insight via `perf`
  - Additional resources

### Linux Servers

**(i) Login to remote Linux system**

- To connect to the remote servers from a Windows machine, use [PuTTY](https://www.putty.org/) or similar app.

- To connect from a Linux or a Mac, use the terminal. From a terminal window, login to one of the CS servers using `ssh`.

```
ssh <netid>@zeus.cs.txstate.edu
```

or

```
ssh <netid>@eros.cs.txstate.edu
```

`zeus` is one of the two _public_ CS servers available for remote access to all CS students. The other one is `eros`. Both can be accessed from outside the university firewall.

The above command will prompt you for the password tied to your netid.  If the userid on your local Mac or Linux system is the same as your netid, then you can simply type `ssh <server_name>.cs.txstate.edu`--without a user specified as part of the `ssh` command, the `ssh` command conveniently uses the user you are currently logged in as on your local machine.

The department and the [CRL](compilers.cs.txstate.edu) research group maintains many other servers for which you can request access. For this class, you will all be granted access to `capi.cs.txstate.edu`, an IBM POWER8 server, and `brooks.cs.txstate.edu`, an x86 server.

**(ii) Getting around a Linux system: files and directories**

List files in current directory

```
ls
```

Almost all Linux commands will accept a set of options that can be used to control its behavior. Options are passed at the command-line using a `-` followed by a single character or `--` followed by the full name of the command option. The single-character format corresponds to the particular option that you want enforced. Here are few useful flags for the `ls` command.

List files in current directory including hidden files

```
ls -a
```

List files and attributes in current directory reverse chronological order

```
ls -ltr
```

Create a directory.

```
mkdir <name-of-directory>
```

e.g.

```
mkdir cs3339
```

Change to another working directory

```
cd cs3339
```

Change to home directory (note that this command is simply `cd` without anything following it)

```
cd
```

**(iii) Getting familiar with the environment**

Get information about the OS and architecture.

```
uname
```

Get more information (-a stands for all).

```
uname -a
```

See who else is logged on and what they are doing.

```
w
```

List the programs (i.e., processes) that are currently running and report resource usage

```
top
```

Get CPU information

```
cat /proc/cpuinfo
```

Get memory information

```
cat /proc/meminfo
```

### Obtaining code samples

Clone the course git repo on this server.

```
git clone https://git.txstate.edu/aq10/CS3339.git
```

Copy the matrix-vector multiplication code (matvec.c) to your working directory.

```
cp <src> <dest>
```

**Remember that anytime you are not familiar with how to use a command, simply type the command without any options or arguments, or type `<cmd> --help`**

### Building and executing

**NOTE: When compiling c code, you use the `gcc` compiler, and when compiling c++ code, you use `g++` compiler.**

The `-c` option tells GCC to only _compile_ the source. This option doesn't perform any _linking_ and therefore doesn't result in a program that we can execute.

```
gcc -c matvec.c
ls -ltr
```

If we want to build the executable, then we need to omit the `-c` flag. The `-o` option (also called "flag") instructs the compiler to change the name of `gcc`'s output file (in this case, the executable).

```
gcc -o matvec matvec.c
ls -ltr
```

There are many things happening behind scenes when going from a source to a binary executable. We can inspect these steps by using the `-v` option.

```
gcc -v -o matvec matvec.c
```

The compiler's first step includes generating assembly (which is then handed off to the assembler). To get to an executable, subsequent steps are carried out by other tools (e.g., assembler, linker) that are packaged with the compiler. If we want to just generate the assembly code then we can pass the `-S` option.

```
gcc -S matvec.c
ls -ltr
```

Take a look at the relative size of the source, asssembly, object and executable files.

**Do these sizes seem reasonable to you?**

To execute a program from the command-line, we simply need the name of the executable and its location ("_path_", in Linux terminology).

```
./matvec 10000 5
```

The matvec program takes two command-line arguments which correspond to the size of the data set and number of times the computation is to be run.

### Measuring performance

**How do we measure the performance of a program?**

We can use the `time` command to get a rough measure of the execution time. The terms "_execution time_" and "_running time_" are synonymous. "_Runtime_" is an overloaded term!

```
time ./matvec 10000 5
```

The `time` command reports three numbers.

- `real` time is the time that elapsed during the execution of the program.
- `user` time is the actual time the (user's) program spent running on the processor.
- `sys` is the time when the _system_ is doing some work either on behalf of this program or some other program.

Often, `real` time is roughly equal to `user` time + `sys` time

**Is the matvec code performing well?**

The answer is, we don't know! Just like at a single number doesn't tell us much. We need some basis for comparison (more on this in the lecture).

Compilers implement many optimizations to try to improve the performance of a program. We can specify the level of optimizations using the `-O` (the capital letter "O") flags. By default, `gcc` will apply only a few optimizations. This is referred to as level `-O0`. Let's rebuild the program at the highest optimization level `-O3`.

```
gcc -o matvec -O3 matvec.c
time ./matvec 10000 5
```

Now, we can say that the version of `matvec` without any optimizations (_-O0_) definitely has worse performance than the optimized one.

We can check the optimizations that are being applied at `-O3` with the `--help=optimizers` option.

```
gcc -Q -O3 --help=optimizers
```

### Exploring a new architecture: POWER8

Log in to `capi.cs.txstate.edu` using ssh. capi is not visible outside the firewall (meaning you first must login to either `eros` or `zeus` and _then_ `ssh` into `capi`). Accounts will be created (or should have been created) for all of you.

```
ssh capi.cs.txstate.edu
```

Check out the OS and architecture information on capi.

```
uname -a
cat /proc/cpuinfo
cat /proc/meminfo
```

Generate assembly code for matvec

```
gcc -S matvec.c
```

Notice how the instructions are different from those on `brooks` which is an x86 machine.

Build the executable with full optimization and measure its performance.

```
gcc -o matvec -O3 matvec.c
time ./matvec 10000 5
```

### Getting performance insight via `perf`

Most recent Linux distributions come with a performance evaluation tool called `perf`. This tool probes the underlying hardware performance counters and can measure a variety of events during program execution. More on this later in the semester.

To use the `perf` tool, simply type `perf` followed by a `perf` command. The `list` command lists the available performance events on this architecture.

```
perf list
```

The above only lists the _named_ events. Typically there are hundreds more on the system.

To get a basic profile we can use the `stat` command, followed by the name the of the program we want to profile. The program can be one that you wrote or any Linux command.

```
perf stat ls
```

Now let's profile the matvec program. Note, for `matvec` we need to indicate the path of the executable (i.e., we must use "./" or construct the fully-qualified path of where the executable is) and the command-line arguments the `stat` command.

```
perf stat ./matvec 10000 5
```

`perf` reports not only the execution time, at a better resolution, but also tells us what's happening inside the processor. This gives us insight about potential performance bottlenecks. Most of the items listed in the `perf` output (e.g., pipeline stalls, mis-predicted branches) are things we will talk about later in the semester.

### Additional resources

**B**ourne **A**gain **SH**ell (BASH)

- Shell scripting: https://www.tutorialspoint.com/unix/shell_scripting.htm
- Bash scripting cheatsheet: https://devhints.io/bash
- Bash guide: http://mywiki.wooledge.org/BashGuide
- "The ultimate guide to Linux for Windows users": https://www.dedoimedo.com/computers/ultimate-linux-guide-for-windows-users.html
- A random assortment of shell scripts: https://github.com/chaseleif/shellscripts
