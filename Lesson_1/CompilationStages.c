//Install vim package for editing-single line comment starts with double slash in C

/* To comment multiple lines use slash star to open and use star slash to end the comment
 *  1) To create or open a file "vi filename.extension"
 *  2) To type, first press INSERT key
 *  3) To exit from file without saving, press ESC ":q!" and press ENT
 *  4) To save and exit from file, press ESC ":wq" and press ENT
 *  5) To install vim editor "sudo apt install vim"
 */

/* Compilation Stages: (gcc Filename.c)
 * Stage 1 - Preprocessor (gcc -E Filename.c -o Filename.i) 
 * Stage 2 - Compilation  (gcc -S Filename.i -o Filename.s)
 * Stage 3 - Assembly     (gcc -c Filename.s -o Filename.o)
 * Stage 4 - Linking (gcc File1.o File2.o -o ExecutableFile)
 */

/*
 * Preprocessor Functionalities:
 * 1) Headers inclusion
 * 2) Comments removal
 * 3) Macro replacement
 * 4) Conditional compilation
 */

//Example for Preprocessor functionalities
#include<stdio.h>

//#define PI 3.147

void main(void)
{
	printf("Testing compilation stages\n");
#ifdef PI
	printf("PI value is %f\n", PI);
#else
	printf("PI is not defined\n");
#endif
		
}
