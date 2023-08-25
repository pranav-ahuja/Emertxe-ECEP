#include "queue.h"

int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    //create the new node
    Queue_t *new = malloc(sizeof(Queue_t));

    if(new == NULL)
    {
        return FAILURE;        
    }
    new->data = data;

    //check if the queue is null
    if(*front == NULL)
    {
        *front = new;
        *rear = new;
        new->link = NULL;
        return SUCCESS;
    }
    else{
        Queue_t *temp = *front;

        while(temp != NULL)
        {
            if(temp->link == NULL)
            {
                temp->link = new;
                *rear = new;
                new->link = NULL;
                return SUCCESS;
            }
            temp = temp->link;
        }
    }


}