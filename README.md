## DESCRIPTION

Basic Linux shell utility commands are implemented on the xv6 operating system, for which functionality is not provided for.

## COMMANDS IMPLEMENTED

  1. ps - Lists out all processes in either sleeping or running state
  2. clear - Clears screen (only when qemu is run on the terminal itself)
  3. exit - Exits from the emulator
  4. touch - Creates a temporary new file for the duration of the current session
  5. wc - Displays number of newline characters, number of words, size of file in bytes and name of file
  
## MAKE INSTRUCTIONS

  Execute:
  ```bash
  make qemu-nox
  ```
  or:
  ```bash
  make qemu-nox-gdb
  ```
  ## NOTES
  
 - 
 ```bash
  make qemu
  ```
  can also be used. However, the commands will be mirrored on both the existing terminal and the new emulator window opened. Also, the clear command will not work on the emulator, but will work on the existing terminal.
  
  - The ps and exit commands are implemented as system calls, thus their actual codes are present in the sysfile.c file.
    - The ps command accesses the process table, which is only accessible in the proc.c file. Thus, the system call calls a function from proc.c, called proc_deets.
    
  - Files pertaining to system calls are as follows:
    - syscall.c
    - syscall.h
    - sysfile.c
    - user.h
    - usys.S
    
  - Any new user program (assume prog.c) to be added to xv6 need to be added to the Makefile under the following heads: 
    - UPROGS: \_prog\
    - EXTRA: prog.c\
