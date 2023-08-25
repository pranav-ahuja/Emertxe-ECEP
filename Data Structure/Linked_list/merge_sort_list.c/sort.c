#include "sll.h"

//sortList() will sort nodes of the list in ascending order  
int sort(Slist **head)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    Slist** h;
    int i, j, swapped;
  
    while(1) {
  
        h = head;
        swapped = 0;
  
        while((*h)->link!= NULL) {
  
            Slist* p1 = *h;
            Slist* p2 = p1->link;
  
            if (p1->data > p2->data) {
                p1->link = p2->link;
                p2->link = p1;                
                *h = p2;
                swapped = 1;
            }
  
            h = &(*h)->link;
        }
        
        if (swapped == 0)
            break;
    }
    return SUCCESS;
}