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

<<<<<<< HEAD
//#define PI 3.147

void main(void)
{
=======
#define PI 3.147
void Arthmetic(int NUM_1,int NUM_2);
void Bitwise(int NUM_1,int NUM_2);
int main(void)
{
	/*
>>>>>>> 538e370 (code updated)
	printf("Testing compilation stages\n");
#ifdef PI
	printf("PI value is %f\n", PI);
#else
	printf("PI is not defined\n");
#endif
<<<<<<< HEAD
		
}
=======
	*/
	/*
	int Rad,Result;
	printf("Enter radius of circle\n");
	scanf("%d",&Rad);
	Result=2*PI*Rad;
	printf("Perimeter of a circle%d\n",Result);
	return 0;
	*/

	int NUM_1,NUM_2,OPT;
		printf("Enter your choice\n");
		printf("1)Arthmetic\n");
		printf("2)Bitwise\n");
	//	printf("3)Logical\n");
	        
		scanf(" %d",&OPT);
		printf("Enter two numbers\n\n");
		scanf("%d %d",&NUM_1,&NUM_2);
	switch(OPT)
	{
		case 1:
			printf("EnterArthmetic\n");
			Arthmetic(NUM_1,NUM_2);
			break;
			
		case 2:
                        Bitwise(NUM_1,NUM_2);
			break;
			/*
		case 'l':
                        printf("Multiplication of two numbers:%d\n",NUM_1+NUM_2);
                        break;
			*/
		
	}
	return 0;
}
	void Arthmetic(int NUM_1,int NUM_2)
	{
		char choice;
		printf("Add,Sub,Multi,Divi:\n");
		scanf(" %c",&choice);

		switch(choice)
		{
			case 'a' :
                        printf("Addition of two numbers:%d\n",NUM_1+NUM_2);
                        break;
                	case 'b':
                        printf("Subtraction of two numbers:%d\n",NUM_1+NUM_2);
                        break;
                	case 'c':
                        printf("Multiplication of two numbers:%d\n",NUM_1+NUM_2);
                        break;
                	case 'd':
                        printf("Division of two numbers:%d\n",NUM_1+NUM_2);
                        break;
                	default:
                        break;
		}
	}
	void Bitwise(int NUM_1,int NUM_2)
	{
		printf("AND Operations:%d\n",NUM_1&NUM_2);
		 printf("OR Operations:%d\n",NUM_1|NUM_2);
		  printf("XOR Operations:%d\n",NUM_1^NUM_2);
		   printf("NOT Operations:%d %d\n",~NUM_1,~NUM_2);
		    printf("LEFT Operations:%d\n",NUM_1<<NUM_2);
		     printf("RIGHT Operations:%d\n",NUM_1>>NUM_2);
	}	


>>>>>>> 538e370 (code updated)
