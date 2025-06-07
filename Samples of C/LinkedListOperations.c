/* Question 1

How do you reverse a singly linked list ? 
How do you reverse a doubly linked list ? 

      Write a C program to do the same */

#include <stdint.h> /* Standard Types Library */
#include <stdlib.h> /* Dynamic Memory Library */
#include <stdio.h>  /* Standard InOut Library */

typedef struct node sNODE;

struct node
{
    uint32_t Data;
    sNODE   *Next;
};

/* Global Variables */
sNODE *HEAD = NULL;
sNODE *TAIL = NULL;

/* Linked List Functions */

void Add(uint32_t Data)
{
    sNODE *Temp;
    Temp = malloc(sizeof(sNODE));
    Temp->Data = Data;
    
    if(HEAD==NULL)
    {
        HEAD = Temp;
        TAIL = Temp;
        HEAD->Next = NULL;
        TAIL->Next = NULL;
    }
    else
    {
        TAIL->Next = Temp;
        TAIL = Temp;
        TAIL->Next = NULL;
    }
    return;
}

void Pop(uint32_t Data)
{
    sNODE *Temp = HEAD;
    sNODE *Prev = HEAD;
    
    if(HEAD == NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
    }
    else if(Temp->Next == NULL)
    {
        if(Temp->Data == Data)
        {
            HEAD = NULL;
            free(Temp);
        }
    }
    else
    {
        printf("Temp:%d ", Temp);
        printf("Node:%d ", Temp->Data);
        printf("Temp->Next:%d\n", Temp->Next);
        Prev = Temp;
        Temp = Temp->Next;
        
        while(Temp != NULL)
        {
            //if(Temp->Data == Data)
            //{
            //    printf("Temp->Data:%d ", Temp->Data);
            //    printf("Temp->Next:%d\n", Temp->Next);
            //    Prev = Temp;
            //    Prev->Next = Temp->Next;
            //    //free(Temp);
            //    printf("Prev->Data:%d ", Prev->Data);
            //    printf("Prev->Next:%d\n", Prev->Next);
            //}
            //else
            {
                printf("Temp:%d ", Temp);
                printf("Node:%d ", Temp->Data);
                printf("Temp->Next:%d\n", Temp->Next);
                Prev = Temp;
                Temp = Temp->Next;
            }
        }
    }
    return;
}

void Dis(uint32_t Data)
{
    sNODE *Temp = HEAD;
    
    if(Temp==NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
    }
    else
    {
        printf("Node:%d ", Temp->Data);
        printf("Temp:%d ", Temp);
        printf("Temp->Next:%d\n", Temp->Next);
        
        while(Temp->Next!=NULL)
        {
            Temp = Temp->Next;
            printf("Node:%d ", Temp->Data);
            printf("Temp:%d ", Temp);
            printf("Temp->Next:%d\n", Temp->Next);
        }
    }
    return;
}

void Rev(sNODE *Node)
{
    return;
}

/* Main Function */

void main(void)
{
    Add(1);
    Add(2);
    Add(3);
    Dis(0);
    Pop(1);
    Dis(0);
    
    return;
}
