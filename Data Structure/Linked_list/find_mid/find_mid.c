#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{ 
    if(head == NULL)
    {
        return LIST_EMPTY;
    }

    Slist *fast = head, *slow = head;

    while(fast->link != NULL)
    {
        if(fast->link->link == NULL)
        {
            slow = slow->link;
            break;
        }
        fast = fast->link->link;
        slow = slow->link;
    }
    *mid = slow->data;
    return SUCCESS;
} 
