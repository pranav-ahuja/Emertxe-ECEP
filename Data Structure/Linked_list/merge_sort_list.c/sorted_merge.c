#include "sll.h"

int sorted_merge( Slist **head1, Slist **head2)
{
    if(*head1 == NULL && *head2 == NULL)
    {
        return LIST_EMPTY;
    }    
    else if(*head1 == NULL)
    {
        *head1 = *head2;        
    }
    else if(*head1 != NULL && *head2 != NULL)
    {
        Slist *temp1 = *head1, *temp2 = *head2;

        while(temp1->link != NULL)
            temp1 = temp1->link;
        
        while(temp2->link!= NULL)
        {
            temp1->link = temp2;
            temp2 = temp2->link;
            temp1 = temp1->link;
        }
    }
    sort(head1);
    return SUCCESS;
}