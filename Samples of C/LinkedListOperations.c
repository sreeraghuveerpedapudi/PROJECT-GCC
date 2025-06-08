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

void Del(uint32_t Data)
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
            Temp->Next = NULL;
        }
    }
    else
    {
        if(Temp->Data == Data)
        {
            HEAD = Temp->Next;
            free(Temp);
            Temp->Next = NULL;
            Temp = HEAD;
            Prev = NULL;
        }
        else
        {
            Prev = Temp;
            Temp = Temp->Next;
        }
        while(Temp != NULL)
        {
            if(Temp->Data == Data)
            {
                if(Prev == HEAD && Temp->Next == NULL)
                {
                    HEAD = NULL;
                    Prev = Temp->Next;
                }
                Prev->Next = Temp->Next;
                
                free(Temp);
                Temp->Next = NULL;
                Temp = Prev->Next;
            }
            else
            {
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
        while(Temp!=NULL)
        {
            printf("Node:%d ", Temp->Data);
            printf("Temp:%d ", Temp);
            printf("Temp->Next:%d\n", Temp->Next);
            Temp = Temp->Next;
        }
    }
    printf("\n");
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
    Add(1);
    Add(2);
    Add(2);
    Add(3);
    Add(3);
    Dis(0);
    Del(1);
    Dis(0);
    //Del(2);
    //Dis(0);
    //Del(3);
    //Dis(0);
    return;
}
