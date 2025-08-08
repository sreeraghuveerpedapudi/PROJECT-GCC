#include<stdio.h>

void Arthmetic(int NUM_1,int NUM_2);
void Bitwise(int NUM_1,int NUM_2);
void logical(int NUM_1,int NUM_2);

void main(void)
{
	int NUM_1,NUM_2,OPT;

	while(1)
	{	
		printf("\n\nEnter your choice\n\n");
		printf("1)Arthmetic\n");
		printf("2)Bitwise\n");
		printf("3)Logical\n");
	        
		scanf(" %d",&OPT);

		switch(OPT)
		{
			case 1:
				printf("EnterArthmetic\n");
				Arthmetic(NUM_1,NUM_2);
				break;			
			case 2:
				printf("Enter Bitwise\n");
       				Bitwise(NUM_1,NUM_2);
				break;				
			case 3:
				printf("Enter Logical\n");	
                		logical(NUM_1,NUM_2);
                		break;
			case 0:
				printf("exit menu\n");
				return;		
			default:
				printf("Invalid option\n");
				break;
	}
	}

}
	void Arthmetic(int NUM_1,int NUM_2)
	{
		char choice;
		printf("Add,Sub,Multi,Divi:\n");
		scanf(" %c",&choice);
        printf("Enter two numbers\n\n");
	    scanf("%d %d",&NUM_1,&NUM_2);

		switch(choice)
		{
			case 'a' :
			printf("Addition of two numbers:%d\n",NUM_1+NUM_2);
			break;
			case 'b':
			printf("Subtraction of two numbers:%d\n",NUM_1-NUM_2);
			break;
			case 'c':
			printf("Multiplication of two numbers:%d\n",NUM_1*NUM_2);
			break;
			case 'd':
			printf("Division of two numbers:%d\n",NUM_1/NUM_2);
			break;
			default:
		    printf("Invalid option\n");
		    break;
		}
	}
	void Bitwise(int NUM_1,int NUM_2)
	{
		scanf("%d %d",&NUM_1,&NUM_2);
		printf("AND Operations:%d\n",NUM_1&NUM_2);
		printf("OR Operations:%d\n",NUM_1|NUM_2);
		printf("XOR Operations:%d\n",NUM_1^NUM_2);
		printf("NOT Operations:%d %d\n",~NUM_1,~NUM_2);
		printf("LEFT Operations:%d\n",NUM_1<<NUM_2);
	 	printf("RIGHT Operations:%d\n",NUM_1>>NUM_2);
	}	
	void logical(int NUM_1,int NUM_2)
	{
		scanf("%d %d",&NUM_1,&NUM_2);
		printf("Logical AND Operations:%d\n",NUM_1&&NUM_2);
		printf("Logical OR Operations:%d\n",NUM_1||NUM_2);
		printf("Logical NOT Operations:%d %d\n",!NUM_1,!NUM_2);
	}


