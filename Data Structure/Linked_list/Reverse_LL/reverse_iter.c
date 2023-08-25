#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head) 
{ 
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *temp = *head, *prev = NULL, *next = NULL;

    while(temp != NULL)
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
} 