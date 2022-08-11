# PDP11 angel-name
PDP-11 (Old-C) Program which determines your 'angel name', as per the algorithm set out in 'algorithm.jpg'.

This program was written for (and compiled by) the SIMH PDP11 emulator running Unix 6.
Edited via the archaic 'ED' editor.

The Unix 6 C compiler set is ancient (and therefore its C syntax, which apparently predates 'ANSI C' a standard set in 1989).

Using the compiler has been very insightful into the semantics of Old C where the internet has been largely uninformative. Among these insights are that the Old C language:
- Doesn't provide a C library in the way it's known today.
- Doesn't have explicit casts (every cast is implicit).
- Doesn't allow initialisation of variables in their declaration.
- Doesn't have keywords 'const', 'unsigned', 'short'.
- The types given to C functions are known only to the function definitions, not declarations (this implies that all arguments must be the same size, i.e. the size of the native int).
- printf() does not recognise '%i' format specifiers but will recognise '%d'. %d is a 16-bit integer.
- printf() recognises '%l' as an unsigned 16-bit integer (not a long).
- Hexadecimal constants are not accepted. Octal is accepted.
- The 'sizeof()' operator does not accept types (i.e. 'sizeof(int)'). Declare an object and take 'sizeof' to it ('int a; a = sizeof(a);' is legal.)
- The 'sizeof()' operator returns 0 for 'long' types (at least on a PDP11).
- The 'sizeof()' operator returns 0 for 'char' types (at least on a PDP11).
- The 'sizeof()' operator returns correct sizes of 'long' and 'char' as long as they're inside structs.
- Notice the escaped hash at the beginning of the file (\#define NAMEBUFSZ 128) - the Unix terminal expects a typewriter interface (no backspace in the sense it is used today), thus the hash '#' is the designated backspace delete button (deletes last character). The '@' deletes the whole current line. In order to enter the hash (trigraphs are rejected by the Unix C compiler) it is necessary to escape it with a backslash. The backslash does not actually enter the file. The backslash remains in the GitHub source text so that anyone copy-pasting into their own terminal emulator do not have to escape the hash themselves.

The PDP11 emulator (and a brief list of instructions on how to run it) are included in the PDP11.zip attachment.
