#include "sll.h"

//remove duplicate data's from list
int remove_duplicates( Slist **head )
{
    //check if the list is empty or not
    if(*head == NULL)
    {
        return FAILURE;
    }
    if((*head)->link == NULL)
    {
        return SUCCESS;
    }

    //Declare the nodes
    Slist *temp1 = *head, *temp2 = temp1->link, *prev = temp1;
    
    if(temp2->data == temp1->data && temp2->link == NULL)
    {
        temp1->link = NULL;
        return SUCCESS;
    }

    while(temp1->link != NULL)
    {
        
        if(temp1->data == temp2->data)
        {            
            //remove the element
            prev->link = temp2->link;
            temp2->link = NULL;
            temp2 = prev->link;        
        }
        else{
            prev = prev->link;
            temp2 = temp2->link;
        }

        if(temp2 == NULL)
        {
            temp1 = temp1->link;
            prev = temp1;
            temp2 = temp1->link;
        }

    }

    return SUCCESS;

}