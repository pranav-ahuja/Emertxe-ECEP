#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
    if(IsQueueFull(q) == SUCCESS)
    {
        return FAILURE;
    }

    if(IsQueueEmpty(q) == SUCCESS)
    {
        q->front = q->rear = 0;
        *(q->Que + q->front) = data;
        q->count++;
        return SUCCESS;
    }
    else{
        q->rear++;
        *(q->Que + q->rear) = data;
        q->count++;        
        return SUCCESS;
    }

}