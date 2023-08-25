#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{   //create a new node
    Slist *new = malloc(sizeof(Slist));

    //check if the memory is allocated
    if(new == NULL)
    {
        return FAILURE;
    }
    //if allocated then populate new->data
    new->data = data;

    //check if the head is equal to NULL, if so then assign the new to head
    if(*head == NULL)
    {
        *head = new;
        new->link = NULL;
        return SUCCESS;
    }
    else{
        Slist *temp = *head, *prev = NULL;

        //if new->data is less than or equal to temp->data
        if(data < (*head)->data)
        {
            new->link = *head;
            *head = new;
            return SUCCESS;
        }

        while(temp->link != NULL)
        {
            // assign prev and increment temp
            prev = temp;
            temp = temp->link;

            //if dataa is greater than prev->data and less than temp->data
            if(data > prev->data && data < temp->data)
            {
                prev->link = new;
                new->link = temp;
                return SUCCESS;
            }
        }

        //else, assign the new to the end of the list
        temp->link = new;
        new->link = NULL;
        return SUCCESS;
    }
} 