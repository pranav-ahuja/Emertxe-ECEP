#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    if(*front == NULL)
    {
        return FAILURE;
    }

    Queue_t *temp = *front;

    *front = (*front)->link;
    temp->link = NULL;
    free(temp);
}