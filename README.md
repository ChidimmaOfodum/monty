## 0x19. C - Stacks, Queues- LIFO, FIFO

### DESCRIPTION
***This is the Monty Project done in fulfilment of ALX Software Development Training program. Monty 0.98 is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCode files.

### FEATURES
- Usage: ``monty file``
	- where `file` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to the program, error message is displayed with an `EXIT_FAILURE`
- If file contains an invalid instruction, error mesage is generated with the line number.
- The monty program runs the bytecodes line by line and stops if either:
	- it executed properly every line of the file
	- it finds an error in the file
	- an error occured

#### COMPILATION
Code is compiled using
```C
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

