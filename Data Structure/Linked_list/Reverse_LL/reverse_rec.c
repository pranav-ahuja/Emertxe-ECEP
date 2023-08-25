#include "sll.h"

int reverse_recursion(Slist ** head, Slist **prev)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *temp = *head, *next = NULL;

    next = temp->link;
    temp->link = *prev;
    *prev = temp;
    temp = next;
    reverse_recursion(&temp, prev);
    *head = *prev;
}