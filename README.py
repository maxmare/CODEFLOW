'''
CODEFLOW
========

#include<stdio.h>

struct vec3{
    union A { int a; int b; int c; } typeA;
    union B { int A; int B; int C; } typeB;
    float x, y, z;
    float r, g, b;
};

main()
{
	printf("Hello World");
}
'''
# reads all source code files in a folder (*.c, cpp, h, hpp, inl),
# extracts all the definitions and creates a file with them, then creates code-browser links from them
# to where they are located in the source files
import sys
import os

# read the folder pased as argument or pre-determined and gather the files that conform to source file pattern in a list

for file in sourceFiles:
	lines = file.split()

