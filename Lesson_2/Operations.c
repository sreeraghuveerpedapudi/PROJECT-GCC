#include<stdio.h>

void Arthmetic(int NUM_1,int NUM_2);
void Bitwise(int NUM_1,int NUM_2);
void logical(int NUM_1,int NUM_2);
void Binary(int Num);

int main(void)
{
	int NUM_1,NUM_2,OPT;

	while(1)
	{	
		printf("\n\nEnter your choice\n\n");
		printf("1)Arthmetic\n");
		printf("2)Bitwise\n");
		printf("3)Logical\n");
	        
		scanf(" %d",&OPT);

		  if (OPT == 0) 
		{
            printf("Exiting menu\n");
            break; 
        }

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
			printf("Exit menu\n");
			return;		
			default:
			printf("Invalid option\n");
			break;
	    }
	}
	return;
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
		printf("Bitwise Operations:\n");
	    Binary(NUM_1);
		printf("\n");
		Binary(NUM_2);
		printf("\n");
		printf("AND Operations:%d\n",NUM_1&NUM_2);
		Binary(NUM_1&NUM_2);
		printf("\nOR Operations:%d\n",NUM_1|NUM_2);
		Binary(NUM_1|NUM_2);
		printf("\nXOR Operations:%d\n",NUM_1^NUM_2);
		Binary(NUM_1^NUM_2);
		printf("\nNOT Operations:%d %d\n",~NUM_1,~NUM_2);
		Binary(~NUM_1);
		printf("\n");
		Binary(~NUM_2);
		printf("\nLEFT Operations:%d\n",NUM_1<<NUM_2);
		Binary(NUM_1<<NUM_2);
	 	printf("\nRIGHT Operations:%d\n",NUM_1>>NUM_2);
		Binary(NUM_1>>NUM_2);
		printf("\n");
	}	
	void logical(int NUM_1,int NUM_2)
	{
		scanf("%d %d",&NUM_1,&NUM_2);
		printf("Logical AND Operations:%d\n",NUM_1&&NUM_2);
		printf("Logical OR Operations:%d\n",NUM_1||NUM_2);
		printf("Logical NOT Operations:%d %d\n",!NUM_1,!NUM_2);
	}

    void Binary(int Num)
    {
    for (int i = 31; i >= 0; i--)  
    {
        printf("%d", (Num >> i) & 1);  
    }
	}

