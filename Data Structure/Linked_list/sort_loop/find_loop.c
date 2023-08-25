#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
    if(head == NULL)
        return LIST_EMPTY;

    Slist *sp = head, *fp = head;

    while(sp != NULL && fp != NULL)
    {
        sp = sp->link;
        fp = (fp->link)->link;

        if(sp == fp)
        {
            return SUCCESS;
        }
    }
    return LOOP_NOT_FOUND;
}