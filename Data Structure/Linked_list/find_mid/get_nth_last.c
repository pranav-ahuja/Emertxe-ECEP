#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{ 
    if(head == NULL)
    {
        return LIST_EMPTY;        
    }

    Slist *first = head;
    Slist *second = head;

    while(pos != 0 && first->link != NULL)
    {
        first = first->link;
        pos--;
    }

    if(pos == 1)
    {
        *data = second->data;
        return SUCCESS;
    }
    else if(pos != 0)
    {
        return FAILURE;
    }

    while(first != NULL)
    {
        second = second->link;
        first = first->link;
    }
    *data = second->data;

    return SUCCESS;
} 