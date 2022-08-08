# angel-name
Program which determines your 'angel name', as per the algorithm set out in 'algorithm.jpg'.

This program was written for (and compiled by) the SIMH PDP11 emulator running Unix 6.
Edited via the archaic 'ED' editor.

The Unix 6 C compiler set is ancient (and therefore its C syntax, which apparently predates 'ANSI C' a standard set in 1989.

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
