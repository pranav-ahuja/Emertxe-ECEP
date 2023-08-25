#include "queue.h"

/* Function to deque the element */
int dequeue(Queue_t *q)
{
    if(IsQueueEmpty(q) == SUCCESS)
    {
        return FAILURE;
    }

    q->front++;
    q->count--;
    return SUCCESS;
}