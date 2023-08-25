#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
    if(*head == NULL)
        return LIST_EMPTY;

    Slist *temp = *head, *to_repeat;
    while(temp)
    {
        if(temp->data == data)
        {
            to_repeat = temp->link;
            while(to_repeat->link != NULL)
            {
                to_repeat = to_repeat->link;
            }
            to_repeat->link = temp;
            return SUCCESS;
        }
        temp = temp->link;
    }
    return DATA_NOT_FOUND;
}