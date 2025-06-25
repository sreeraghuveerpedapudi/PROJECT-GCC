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
sNODE *indirect = NULL;
sNODE *TAIL = NULL;

/* Linked List Functions */
void Dis(uint32_t Data);
void Add(uint32_t Data);
void Del(uint32_t Data);
void Rev(uint32_t Data);
void Rem(sNODE *entry);

void Rem(sNODE *entry)
{
    // The "indirect" pointer points to the
    // *address* of the thing we'll update
    indirect = HEAD;
    
    // Walk the list, looking for the thing that
    // points to the entry we want to remove
    while (indirect != entry)
    indirect = indirect->Next;
    
    // .. and just remove it
    indirect = entry->Next;
}

/* Main Function */
void main(void)
{
    Add(1);
    Add(2);
    Add(3);
    Add(1); //BUG HERE
    Dis(0);
    Rev(0);
    Dis(0);
    Del(1);
    Dis(0);
    Del(2);
    Dis(0);
    Del(3);
    Dis(0);
    Add(1);
    Add(2);
    Dis(0);
    Rev(0);
    Dis(0);
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
    sNODE *Curr = HEAD;
    sNODE *Prev = NULL;
    
    if(Curr!=NULL && Curr->Data == Data)
    {
        HEAD = Curr->Next;
        free(Curr);
        return;
    }
    
    while(Curr!=NULL && Curr->Data != Data)
    {
        Prev = Curr;
        Curr = Curr->Next;
    }
    
    if(Curr == NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
        return;
    }
    
    Prev->Next = Curr->Next;
    free(Curr);
    return;
}

void Rev(uint32_t Data)
{
  sNODE *Prev = NULL;
  sNODE *Curr = HEAD;
  sNODE *Next = NULL;
  
  while(Curr!=NULL)
  {
    Next = Curr->Next;
    Curr->Next = Prev;
    Prev = Curr;
    Curr = Next;
  }
  HEAD = Prev;
  return;
}
