- O que faz um sistema operativo?
	- A gestão dos recursos de hardware do pc

`se tiver dúvida, mandar para dabreu@dei.uc.pt e colocar tag [OS]`

---
# T 1

- usar o mail do dei ou da uc para dúvidas

- Saber como funciona um sistema operativo
- Saber utilizar e programar utilizando funções fornecidas pelo SO, tirando partido das suas potencialidades
- Programação corrente
- Programação em C

#### Tópicos 

- Funções de um SO
- **Gestão de processosMulti-threading**
- **Programação concorrente**
- **IPCs**: Memória partilhada, pipes, named pipes, filas de mensagens, memory-mapped files, semáforos
- **Sinais**

#### Bibliografia 

teórica: 
- **Operating System Concepts**
- **Operating Systems: Three easy concepts**

prática:
- **Unix Systems Programming
- **The linux programming Interface


---

# Linux

#### Components

- **Kernel** - OS Core
- **FileSystem** - deals with files 
- **Shell** - commands writer

Filesystem in linux follows a hierarchy. Many folders predefined for specific purposes

Each directory has at least **two files**
- **.** - current directory
- **..** - parent directory
- **~** - user home directory

-> *Files are case sensitive*
-> *Everything is a file*

### File types

- **Regular Files**
- **Directories**
- **Special files** ( ex: communicate with i/o devices)

PS: See filesystems supported

#### Types of permissions
	
==Security mechanism==
	It is the same in Linux as Unix.

==User permissions==
	They can be attributed at **groups of users**, where every user in the group has permission to access certain files

==change permissions== 

```chmod (ugoa)(+-)(rwx) (file)```
**UGOA** -> u = user who owns file; g = users in file group; o = other users; a = all
**"+"** -> give permissions
"-" -> remove permission
**"file"** -> targeted file

```chmod (octal mode) (file)```
octal represents the binary of the user, for example:
	**111** -> *rwx* (read write execute)
	**011** -> *wx* (write execute)
	**1** -> *x* (execute)

#### Basic Shell Commands

*Metacharacters*: 
	**\*** -> file substitution wildcard (zero or more chars)
	**?** -> file substitution wildcard (one character)
	**\[]** -> file substitution wildcard (any character between brackets)
	**;** -> command separator

### Variables of the Shell

- **HOME** -> current user directory
- **PATH** -> a colon-separated list of directories in which the shell looks for commands
- **PS1** -> The primary prompt string which is displayed before each command. The default value is "'\s-\v\\$"
...

## Makefile

```makefile
prog:                                    // to build this
	main.o global.o input.o              // I need all this
	gcc main.o global.o input.o -o prog  // then this command is executed

input.o:
	input.c input.h global.h
	gcc input.c -c -o input.o

global.o: 
	global.c global.h 
	gcc global.c -c -o global.o

main.o: 
	main.c input.h global.h
	gcc main.c -c -o main.o
```


---

# PL 2

- ./ -> reference to the current directory
- ../ -> reference to the "father" directory (root)

	How does **|** work? 
		**|** -> **pipe** -> Analyzes content that gets through it

##### Commands

| command      | return                                                  |
| ------------ | ------------------------------------------------------- |
| *jobs*       | shows all active or suspended programs                  |
| *fg %number* | (foreground) relive suspended program of index "number" |
| *ps -fg*     | shows processes in foreground                           |
| *ps*         | lists processes                                         |


---

# T/TP 2

![[SO-T-02-OPERATING_SYSTEMS_v2025.pdf]]
![[SO-TP-02-Processes_v2025.pdf]]

==Hardware== -> Operating System 
		
- `system of applicatios / users`

==Operating System (OS)== -> allows the **isolation of the hardware from the programs** that run on the computer
		
- `controls the execution of programs to prevent errors and improper use of the computer`

- `it is a ` **resource manager / allocator**

	resources managed (all):
		- *Process*
		- *Memory*
		- *File-system*
		- *Mass-storage*
		- *I/O*

- `Decides between conflicting requests for efficient and fair resource use`

A general-purpose OS usually includes: 
- **Kernel** (the OS part that's always running on the machine)
- **Middleware frameworks** (ease application development)
- **System programs that help to manage the system**

- `Sharing resources among applications`
- `Making efficient use of limited resources`
- `Protecting applications from each other`

##### Classification of Operating Systems

==Interface==

- *CLI*
	- Command Line Interface
- *Bash Interface*
	- commands are entered in files
- *GUI*
	- Graphical User Interface
- *Voice Recognition*

==Users==

- *Multi-user*
- *Mono-user*

==Tasks==

- *Single-Task*
	- can support only a single task at any time, and they are handled sequentially
- *Multi-task*
	- executes more than one task at a time, by sharing resources

==Real-time Operating Systems (RTOS)==

- Operating systems that have strict bounds and have a predictable behavior

==Open / Closed OS==

- *Proprietary*
- *Open Systems*
	- have standardized programming interfaces and peripheral interconnects
- *Open-source systems (GPL licence)*
	- source code available (rather than closed-source binary)

- **mode-bit = 0** -> processing in the *kernel mode*
- **mode-bit = 1** -> processing in the *user mode* 
- **trap** -> transition of the process to the *kernel*

*start-up* -> ==booting==
- is when the computer is loading the kernel
- most computers have multistage boot

#### Power up the computer

- ==Test Operation:==

1. in the power-up/reset, the *CPU* executes a *jump* instruction to a *pre-defined address* where the initial *boot loader* located in *nonvolatile firmware* (BIOS or UEFI) is run
	1. **BIOS** - <u>Basic Input Output System</u>
	2. **UEFI** - <u>Unified Extensible Firmware Interface</u>
2. the initial *boot loader* program executes *tests* for *verifying the correct operation* of the CPU (subset of instructions) and RAM (basic tests)
	1. Power-on self-test, also known as *POST*
3. If OK, a second boot loader is started

- ==Sequence startup (boot) OS:==
1. A second boot loader is started, normally from the first sector of the boot device. This second boot loader may be able to start the OS, but normally it only knows the location of the remainder of the **bootstrap loader** program, which in turn *locates the kernel, loads into main memory and starts its execution*.
	1. ex: *GRUB*, for Linux; allows selection of kernel from multiple disks, versions, kernel options

#### BIOS vs UEFI

==UEFI== (Unified Extensible Firmware Interface)

- supports *all the functionalities of the BIOS*
- can be saved in *any disk* support (disk, flash memory, ...)
- *faster than BIOS*
- allows for *bigger disks*
- *better GUI*
- allows *secure boot*

##### OS Initialization

- OS performs it's boot "routines":
	- ==hardware== - initialization of **registers of the controllers**, the system interrupts.
	- ==software== - initialization of **data structures** that represent the various **system resources and algorithms** that support the management of these resources
- Creation of the first cases:
	- The system **auxiliary processes** (login, file system, network)
	- **the interpreter commands** (command line e.g. sh, bash, csh, ...) or windows
- "Wait for Interrupt"

-> ==Wait for Interrupt==
- After booting, the OS is "quiet" **waiting for work** and there is a ***hardware interrupt***
	- OS performs a task that handles the interruption (e.g., CPU clock interrupts, OS updates the time)
- The OS is "quiet" and **a program requests a service through a software interrupt** or ***trap***
	- OS triggers a task that runs a service (e.g., print a string on the screen)

### Types of Operating Systems

- **Monolytic OS**
	- most of the operations are executed directly in the kernel
	- slower but safer
- **Microkernel**
	- only the most basic functions are executed in the kernel, the rest are in user mode
	- faster but less safe
- **Hybrid Kernel**

# TP 2

#### Process Management

- Each process has an unique *identifier* (**PID**) 
- Each process has a father (identified as **PPID**)

functions in C:

| function                | return                                                                                                                                                      |
| ----------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **pid_t getpid(void)**  | returns the *PID* of the *current process*                                                                                                                  |
| **pid_t getppid(void)** | returns the *PID* of the *parent process*                                                                                                                   |
| **pid_t fork(void)**    | creates a *new process* which *inherits all it's father's state*. Returns  ***0 to the child's process*** and ***the child's PID to the parent's process*** |

---

# PL 3

==pid_t== 
	-> **structure type in C**
	-> 

==fork()==
	-> **duplicates the process state of the father**
	
```C
pid_t mypid;
pid_t childpid;

mypid = getpid();
childpid = fork();

if(childpid == 0){ // child process
	// sleep(1);
	printf("child mypid() :%ld\n", (long)mypid);
	printf("child getpid() :%ld\n", (long)getpid());
	printf("child getppid() :%ld\n", (long)getppid());
} else { // father process
	// sleep(1);
	printf("mypid() :%ld\n", (long)mypid);
	printf("getpid() :%ld\n", (long)getpid());
	printf("getppid() :%ld\n", (long)getppid());
}
```

- *the SHELL is the father of the process (when bash script executed in the shell)*

==ps== (shell command)
	-> process status

==pstree== (shell command)
	-> shows processes tree (*in my machine the father process is* **systemd**)

==ps -aux | grep 1== (shell command)
	-> 

$$processes$$

- the ==bootloader== is the **first process to initiate in startup**

- then at startup when it *selects the OS* to boot, the father process becomes ==Init== and it is **always running (until shutdown)** and generates all the other default processes

- a child process is ==**orphan**== when it's **father process stops running before it finishes executing**

- then the orphan process is ==adopted== by the **init process (pid 1)**

- a process is ==zombie== (Z) when it is **asleep** or **suspended** (but not finished, as when you do ^Z)
	- ``sometimes a process dies and the father process has not acknowledged his death (it leaves leftover bits), then it can MAYBE be adopted by Init, but usually it gets forgotten and left in a limbo``

There should be no Orphan Processes in UNIX Systems 

```bash
systemd
```
![[Pasted image 20250217192836.png]]

[states of processes](https://www.geeksforgeeks.org/states-of-a-process-in-operating-systems/)

**the two-state model**
![[Pasted image 20250217190204.png]]

1. *Running* -> the process is activally using the CPU to work
2. *Not Running* -> the process is not currently using the CPU. It could be waiting for something, like user input or data, or it might just be paused.
3. ***dispatcher*** -> When a new process is created, it starts in the ****not running**** state. Initially, this process is kept in a program called the [**dispatcher**](https://www.geeksforgeeks.org/difference-between-dispatcher-and-scheduler/) 

**the five-state model**
![[Pasted image 20250217190344.png]]

---

# T 3

content
- **Processes**
	- what is a process
	- Process status
	- Process creation / termination
- **Threads**
	- What is a thread
	- Multithreading

Program --> *binary code (executable)*
Process --> The living "image" of a *program running (active entity)*

## **A process in Memory**
![[Pasted image 20250220152914.png]]

### Text

Where the <u>code of the program</u> goes
- Consists of the **machine instructions that CPU executes**
- Usually **shareable** (so that only a copy needs to be in memory, for frequently executed programs)
- **Often read-only**, to prevent modifications to instructions
- Called **.text** segment

### [^1]Data

Where all <u>variables</u> are

- ==.data== -> *global* and *static variables*, **initialized to non-zero**
	- This is the **initialized data segment**
	- Contains global and static variables **specifically initialized by the program**

- ==.bss== -> *global* and *static variables*, **non-initialized or initialized to 0**
	- *.bss* aka **Uninitialized data segment**
	- Data in this segment is **initialized by the kernel**, to **0** or **null**, **before the program starts executing**

- ==**heap**== --> Where all **dynamically allocated memory** is set
	- e.g., as a result of **malloc()**

- ==**stack**== --> Where all **automatic variables** exist
	- *Variables* that are **automatically created** and **destroyed** in methods
		- *Including return address of functions, machine registers, etc.*
	- It **grows down** (*higher to lower addresses*)


![[Pasted image 20250220154534.png]]

#### Where does everything go? (Example)
![[Pasted image 20250220154957.png]]

*flags*
- **-save-temps** --> compile and store temporary immediate files  ```
```bash
$ gcc -Wall -save-temps my_prog.c -o my_prog
```
	- my_prog.i – preprocessed file
	- my_prog.s – assembly file
	- my_prog.o – object file
	- my_prog – executable file

- List section sizes (in bytes) and total sizes of executable
```bash
$ size my_prog
```
	 text   data   bss        dec        hex      filename
	 1259   1548   10485824   10488631   a00b37   my_prog

- Display assembly code
```bash
$ less my_proj.s
```

- Displays information from the object file
```bash
$ objdump -t my_prog | egrep '\.data'
$ objdump -t my_prog | egrep '\.bss'
$ objdump -t my_prog | egrep '\.text’
```

##### Processes states
![[Pasted image 20250220162019.png]]

### **PCB** - Process Control Block

- Represents a process in the OS
- One of the most important data structures of the OS

it includes:

```
▪ Process state
▪ Process identifier
▪ Program counter
▪ CPU registers
▪ CPU scheduling information
▪ Memory-management information
▪ Accounting information
▪ I/O status information
▪ List of open files
```

![[Pasted image 20250220162531.png]]

#### Process Context

- A process context is constituted by all the *data* that represents the *current state* of a process, which is saved on the *PCB*. It represents the ***context** within which the process executes*. When the *context switch* occurs the **entire system context is replaced**.
![[Pasted image 20250220163057.png]]


---

# TP 3

1.  IPC - Interprocess Communications
2. Shared Memory
3. Semáforos

## IPC (InterProcess Communications)

==System V IPC API==
- overview
![[Pasted image 20250220171035.png]]

==System V Object Persistence==
- System V IPC objects have kernel persistence: they remain available until kernel shutdown or explicit deletion

- <u>Advantages</u>:
	- **processes** can *access the object*, *change its state*, and then *exit without having to wait*; other processes can come up later and check the (modified) state

- <u>Disadvantages</u>:
	- **IPC objects** *consume system resources* and *cannot be automatically garbage collected* - (hence the need of enforcing limits on their quantity)
	- it’s hard to determine when it is safe to delete an object

==Shell Manipulation of IPCs==

```bash
$ ipcs      # lists available System V IPC objects
$ ipcs -l   # shows system limits on IPC object counts
$ ipcrm     # deletes IPC objects (that the user owns)

# On Linux, /proc/sysvipc/ provides a view on all existing IPC objects
```

An example of a shell script to automatically **clean** SysV IPCs

```bash
#!/bin/bash
ME=`whoami`
IPCS_S=`ipcs -s | egrep "0x[0-9a-f]+ [0-9]+" | grep $ME | cut -f2 -d" "`
IPCS_M=`ipcs -m | egrep "0x[0-9a-f]+ [0-9]+" | grep $ME | cut -f2 -d" "`
IPCS_Q=`ipcs -q | egrep "0x[0-9a-f]+ [0-9]+" | grep $ME | cut -f2 -d" "`
for id in $IPCS_M; do
ipcrm -m $id;
done
for id in $IPCS_S; do
ipcrm -s $id;
done
for id in $IPCS_Q; do
ipcrm -q $id;
done
```

remember: <u>ALWAYS CLEAN UP</u>

Overview of ==POSIX IPC API==
- it implements:
	- *Message queues*
	- *Shared memory*
	- ***Semaphores (thread safe!!)***
	
	--> The POSIX.1b real-time extensions defined a set of IPC mechanisms that are analogous to the System V IPC mechanisms

![[Pasted image 20250220172431.png]]

==Shell Manipulation of IPCs==

- *POSIX shared memory* and semaphores are visible at:
```bash
$ /dev/shm
```

![[Pasted image 20250220172711.png]]

![[Pasted image 20250220172729.png]]

**Advantages**

| POSIX IPC                                                                                                                     | SYSTEM V                                                                                                                                                                                                                                            |
| ----------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Simpler interface                                                                                                             | Portability                                                                                                                                                                                                                                         |
| The use of names instead of keys, open, close, and unlink functions, is more consistent with the traditional UNIX file model. | (System V IPC is specified in SUSv3 and supported on nearly every UNIX implementation. By contrast, each of the POSIX IPC mechanisms is an optional component in SUSv3. Some UNIX implementations don’t support (all of) the POSIX IPC mechanisms.) |
| Objects are reference counted. It will be destroyed only when all processes have closed it.                                   |                                                                                                                                                                                                                                                     |
| interface is <u>Multithread Safe</u>                                                                                          |                                                                                                                                                                                                                                                     |

## Shared Memory

==**WHY**==

1. *syscalls* are **slow**
2. *copying through the kernel* is **slow**

![[Pasted image 20250220173705.png]]

| Advantages                     | Disadvantages  |
| ------------------------------ | -------------- |
| (Almost) No kernel involvement | very dangerous |
| Very fast                      |                |
![[Pasted image 20250220173850.png]]

==**HOW**==

- Each **process** has an **address space**
	- Each address space corresponds to a page table. There are as many page tables as there are processes
- Shared memory corresponds to *putting the same “real memory pages” in the page tables of two different processes*

![[Pasted image 20250220174114.png]]


```c
int shmget(key_t key, int size, int flags)
```
> Obtains an identifier to an existing shared memory or creates a new one.

- “*key*” can be IPC_PRIVATE (which creates a new unique identifier), or an existing identifier.
- “*size*” its the **shared memory size in bytes**
- “*flags*” ([^2]**IPC_CREAT** or [^3]**IPC_EXCL**), normal mode flags. When ORed with IPC_CREAT creates a new one.
	- When using IPC_CREAT always define the permissions of the new shared memory

```c
ftok()
```
- can be used to generate a number based on a filename.

```c
int shmctl(int shmid, int cmd, struct shmid_ds* buff)
```
- Provides a variety of control operations on the shared memory.
	- `“shmid” is the value returned by shmget()`
	- `“cmd” is the command (most usually: IPC_RMID to remove it)`
	- `“buff” a structure used in some control operations`

```c
void *shmat(int shmid, const void* where, int flags)
```
- Maps a certain shared memory region into the current process address space.
	- “*shmid*” represents the shared memory identifier “shmid” returned by `shmget()`
	- “*where*” represents an unused address space location where to map the shared memory (normally, use `NULL`)
	- “*flags*” represent different ways of doing the mapping (typically 0)
```c
int shmdt(const void* where)
```
- Unmaps a certain shared memory region from the current address space.
	- “*where*” represents an address space location where the shared memory was mapped

### How attaching works

![[Pasted image 20250220175447.png]]

## SYNCHRONIZATION OF PROCESSES
# SEMAPHORES (SYSTEM V & POSIX)

### What’s wrong with this routine?

```c
void print_work(const char* work, int user)
{
	send_to_printer(“--- JOB of %d ---\n”, user);
	send_to_printer(“%s\n”,work);
	send_to_printer(“--- END OF JOB ---\n”);
}
```
![[Pasted image 20250314010324.png]]

#### How to fix it? -> **semaphores**

- A semaphore is a ==synchronization== object
	- Controlled access to a *counter* (a value)
	- Two operations are supported: ***wait()*** and ***post()***
	- Can also be used as a *resource counter* – to control access to finite resources!

- ==**wait()**==
	- If the *semaphore is positive*, **decrement** it and continue
	- *If not*, **block** the calling process (thread)
- ==**post()**==
	- **Increment** the semaphore value
	- *If there was any blocked process* (thread) due to the semaphore, **unblock** one of them.

### Corrected version

![[Pasted image 20250314010934.png]]


---


[^1]: Contents of uninitialized data segment are **not stored in the program file on disk**, because the **kernel sets them to 0** *before* the program starts running. *Only text segment and the initialized data need to be saved in the program file.*

[^2]: Create a new segment. If this flag is not used, the shmget() will find the segment associated with key and check to see if the user has permission to access the segment.

[^3]: This flag is used with IPC_CREAT to ensure that this call creates the segment. If the segment already exists, the call fails.

---

# PL 4

## IPCs - Interprocess Communications

Mechanisms that allow *exchange of data* and *coordination among processes*, even in **protected memory environments**. Those methods are essential for complex systems, where processes need to cooperate or share resources.

```bash
ipcs
```
- when executed  it displays:
```bash
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x0020125c 0          postgres   600        56         6
0x00501480 1          postgres   600        56         6
0x00000000 6          teomarques 600        524288     2          dest
0x00000000 9          teomarques 600        524288     2          dest
0x00000000 65546      teomarques 600        4194304    2          dest
0x00000000 65577      teomarques 600        16777216   2          dest
0x00000000 65580      teomarques 600        33554432   2          dest
0x00000000 65581      teomarques 600        67108864   2          dest

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
```
- if message queues is clean and semaphore arrays is also clean, then everything is OK and there is no hanging process
- if they are not cleared, then it means there are hanging processes and you must end them, with:
```shell
ipcrm
```
- shows system limits on IPC object counts
```shell
ipcs -l
```

## Semaphores

**A semaphore is a synchronization object**

- Controlled access to a counter (a value)
- Two operations are supported: wait() and post()
- Can also be used as a resource counter – to control access to finite resources!

==***wait()***==
-> If the semaphore is **positive**, *decrement* it and continue
-> If **not**, *block the calling process* (thread)

==**post()**==
-> **Increment** the semaphore value
-> If there was any **blocked process** (thread) due to the semaphore, **unblock** one of them

*==thread safe==*
-> the semaphore operations are *atomic*

*==not thread safe==*
-> the semaphore operations are *prone to errors*, which can cause memory problems

**binary semaphores** -> _mutex (value is either 0 or 1)_
**non-binary semaphores** -> _can get other values_

**mutex** -> used only and only when I want to change the value of that variable
1

==Producer Consumer==

-> for there to be a consumer, there must be a product. When the queue is filled with products, the producer must stop producing, and when a consumer gets at least one product, he produces again.

==Reader Writer==

-> Reader can read n processes at the same time, but only one can write at the same time.

v
recommendation for the assignment: use **POSICX** because SystemV is deprecated

for the project:

	ipcs
	message queues
	processes and threads
	semaphores
	shmat (other shm commands)

---

# T 4
(missing)

---
# TP 4

## Threads

==Single-threaded vs Multi-threaded==
![[Pasted image 20250227172324.png]]

==**WHY?**==

% continuar %

---

# T 5

![[SO-T-05-DEADLOCKS_v2025 1.pdf]]

## Deadlocks

- Permanent blocking of a set of processes that either compete for system resources or communicate with each other
- For example, if 4 cars in an intersection want to overtake each other
- There can only be a deadlock if effectively the resources get blocked and one of them have to release it to the execution to go forward

==**Dining Philosophers**==
...

1. Request resources
2. Use resources
3. Release resources

(Deadlock happens then the following 4 conditions happen at the same time)
*Mutual Exclusive*
	Only 1 process can use one resource at a time

*Hold-and-wait*
	A process holds a resource and is waiting for additional ones - a process requests all of its required resources at a time

*No-preemption*
	Resources cannot be preempted - can only be released voluntarily

*Circular wait*
	Process waits for a resource that is being used by another process

#### Resource-Allocation graph (examples)
... % pegar imagens do slide T5 %

Resource-Allocation graphs analysis

- ...
- ...
- ...

### Treating Deadlocks in the OS

1. **Prevent** deadlocks to ensure that the system never enters a deadlock state
2. **Avoid** deadlocks to ensure that the system never enters a deadlock state
3. **Allow** a deadlock state, **detect** it and **recover**
4. **ignore** deadlocks
	- it is up to the programmers to handle deadlocks
	- used in Linux and Windows

(if one of the previous four conditions fail, there is NO deadlock)

### Prevention of:

*Mutual Exclusion*
	Have sharable resources (e.g. read-only files)
	- however, not all resources can be sharable!

*Hold-and-wait*
	Guarantee that all the resources are requested and allocated before beginning execution
	- if all resources cannot be guaranteed, release the ones allocated
	...
	...

*No-preemption*
	If a process holding certain resources has denied a further request, that process must release its original resources
	If a process requests a resource that is currently held by another process, the OS may preempt the second process and require it to release its resources

*Circular wait*
	...
	Example:
		- Without linear ordering of resources
		...
		% get images of the example %

### Dining philosophers (example)

Can it be prevented?

*Proposal 1*
- ...

*Proposal 2*
- Before taking a fork(), a philosopher locks a MUTEX
- The philosopher can (...)
- ...

% get the code for solution %
...

## Safe state

In a system with a fixed number of processes and resources:
- The *state* of the system is the current allocation of resources to process
- A *safe sequence* exists when all processes may access their needed resources without resulting in a deadlock
- A *safe state* is when there is at least one safe sequence of resources allocation that does not result in a deadlock
- ...

#### Banker's Algorithm

...

#### Deadlock detection

if a system does not use deadlock-prevention nor avoidance algorithms, a deadlock may occur

*deadlock detection* strategies grant resources whenever possible and perform an algorithms to detect if a deadlock has occurred - does not prevent the deadlock, only detects it

An algorithm to recover from the deadlock is also needed

##### How to detect deadlocks?
% see how and the algorithm %

---

# TP 5
# Threads and Synchronization

![[SO-TP-05-Threads_synchro_2_v2025.pdf]]

## Monitors & Semaphores

- can be implemented in Java
- Semaphores provide an effective mechanism for *synchronization*, when correctly used
- Using semaphores incorrectly can lead to errors difficult to detect as they depend on specific execution sequences
- Wait and Signal operation may be scattered throughout a program, with a combined result difficult to preview, or incorrectly used by some programmers 
- A monitor is a high-level programming-language synchronization construct that provides similar functionality while easier to control

### Monitors
A monitor is an abstraction where only one thread or
process can be executing at a time.
- Normally, it has associated data
- When, inside a mirror, a thread executes in mutual exclusion

![[Pasted image 20250306171529.png]]

> A monitor in Java

```java
import java.util.*;
public class Buffer
{
	// -------------------------------------- PROTECTED DATA
	private final static int MAX_SIZE = 10;
	
	private LinkedList<Integer> elements;
	private int totalElements;
	// --------------------------------------
	public Buffer()
	{
		elements = new LinkedList<Integer>();
		totalElements = 0;
	}
	// -------------------------------------- 
	/*
	Only one thread can be inside these methods at a time;
	The others wait outside
	*/
	public synchronized void putValue(int e)
	{
		// ...
	}
	public synchronized int getValue()
	{
		// ...
	}
}
```
- So far, monitors looked a lot like MUTEX...
- Two more primitives are provided with a monitor:

==**wait()**==
- Suspends the execution of the current thread, immediately relinquishing the monitor. The thread is put on a blocked threads list, waiting to be **notified** that “something” has changed.
==**notify()**==
- Informs one of the threads that is waiting for something to change that **“something” has changed**. Thus, one of the awaiting threads is put on the “ready to execute” list. Note that only after the thread that has called notify exits the monitor, will the thread that was awaken be allowed to check what has changed and enter the monitor!
- [==**notifyAll()**== -> Notifies all waiting threads to check the condition]

<u>Important!</u>
- wait() and notify() are **not** like wait() and post() in semaphores. If notify is called when there is no awaiting thread, it is lost. There is no associated counter, only the means to notify threads that things changed.

%falta o resto a partir de condition variables%

---

# PL 5

==**MUTEX**== is used to:
1. *protect* shared variables
2. *protect shared resources* by ensuring that **only one thread** (or process) **can access** a particular section of code or data at a time

- Essentially it is a ***synchronization tool***

> **==MONITOR Thread==**

- Unique thread that "listens" to the worker threads until it receives some information or change in the **state** of the worker threads. 
- sometimes also called a “manager” or “supervisor” thread
- isn’t directly responsible for performing the primary workload. Instead, its job is to oversee and manage the worker threads. This may include:
	- **Health Monitoring:** Regularly checking that worker threads are running correctly (or have not become unresponsive or failed).
	- **Resource Management:** Tracking performance metrics such as CPU usage or memory consumption, and possibly scaling the number of worker threads up or down based on the current load.
	- **Task Coordination:** Distributing work or reassigning tasks if a worker thread fails, or logging progress and results.

> **==WORKER Thread==**

- These are the threads that actually do the “work”.
- They are responsible for **processing tasks**, **handling computations**, or performing any **background operations** (for example, processing incoming jobs from a task queue). In many applications, a pool of worker threads is created so that multiple tasks can be processed concurrently.
- Example: 
	- in a web server, when a request comes in, one of the worker threads might pick it up, perform the necessary processing, and then return the result.

---

# T 6

%%falta%%

## Dispatcher

- %%falta%%

*Dispatcher operation*
%%adicionar imagem do slide%%

## Scheduling Criteria

 ==CPU utilization==
 - Keep the CPU as busy as possible
==Throughput==
- Number of processes that complete their execution per time unit
==Turnaround time==
- Amount of time to complete a particular process
==Waiting time==
- Amount of time a process has been waiting in the ready queue
==Response time==
- Amount of time it takes to a process to respond 

### Scheduling Algorithms

%%Pesquisar%%

## FCFS (First-come first-served)

- The process that requests the CPU gets it first
- Simple to manage with a FIFO queue
- Average waiting time is often long
- This is a **non-preemptive** algorithm
	- A process keeps the CPU until it terminates or requests I/O

%%detail the algorithm%%

## SJF (Shortest-Job-First)

==Nom-preemptive -> **SPN**==
- %%explain%%

==Preemptive -> **SRT**==
- %%explain%%

### How to predict the next CPU burst time?

%%show graph%%

## Priority Scheduling

- A priority number is associated with each process (can be anything measurable)
- The CPU is allocated with the process with the highest priority
- %%...%%

<u>Problem:</u> -> ==Starvation==
- Low priority processes may **never** execute

<u>Solution:</u> -> ==Aging==
- As time progresses, the *priority* of the process **increases**

%%add images%%

## Round-Robin (RR)

- Designed especially for time-sharing systems
- Similar to FCFS with *added preemption*
	- Reduces the penalty that short jobs suffer with FCFS by using preemption based on a clock
- Each process gets a small unit of CPU time (**time quantum**), usually 10-100 milliseconds. After this time has elapsed, the process is preempted and added to the end of the ready queue.
- %%add%%

- if there are %%...%%

==Performance==
 - *q large* -> FCFS
 - *q small* -> q must be large with respect to context switch %%...%%

%%add example%%

## HRRN (Highest Response Ratio Next)

- Choose next process with the <u>HIGHEST</u> ratio ( **R** )

%% add the equation%%

## Multilevel Queue Scheduling

- Used when processes are easily classified into different groups (%%...%%)
- %%add remaining%%

%%examples%%

## Multilevel Feedback Queue Scheduling

- %%add characteristics and example%%

%%add examples%%

### Comparison of Scheduling Algorithms

- %%add comparisons%%

---
# TP 6

## Signals

- A signal is a *software interrupt*
- Signal *notify a process* that an event has occurred

- **HW (Hardware)** can also create events
	- e.g., as result from a division by 0
	- This events are detected by the HW, received by the kernel and sent to the process as <u>signals</u>

- Signals have 2 main categories:
	1. ==Standard POSIX reliable signals== (POSIX.1 standard)
	2. ==POSIX real-time signals== (POSIX.1b standard)

- Some advantages of POSIX real-time signals:
	- Provide additional signals to be used by applications
	- Signals are queued - if multiple instances of a signal are sent, the signal will be received many times
	- Data may be sent together with the signal

> Not good to synchronize processes with signals

---

# Project

## A Concurrency-Focused Blockchain Simulation