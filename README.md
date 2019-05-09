CODEFLOW
========

Online Memento

/* Hello World program */
#include<stdio.h>

main()
{
	printf("Hello World");
}

# reads all source code files in a folder (*.c, cpp, h, hpp, inl),
# extracts all the definitions and creates a file with them, then creates code-browser links from them
# to where they are located in the source files
import sys
import os
