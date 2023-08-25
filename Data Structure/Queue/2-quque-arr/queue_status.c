#include "queue.h"

int IsQueueFull(Queue_t *q)
{
    if(q->count == q->capacity)
    {
        return 0;
    }
    return 1;
}

int IsQueueEmpty(Queue_t *q)
{
    if(q->rear == -1 || q->front > q->rear)
    {
        return 0;
    }
    return 1;
}