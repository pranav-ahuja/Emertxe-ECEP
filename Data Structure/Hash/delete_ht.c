#include"hash.h"

int destroy_HT(hash_t *arr, int size)
{
    hash_t *temp1 = NULL;
    for(int i = 0; i<size; i++)
    {
        hash_t *temp = arr[i].link;
        arr[i].value = -1;
        while(temp)
        {
            temp1 = temp->link;
            temp->value = -1;
            free(temp);
            temp = temp1;        
        }
        arr[i].link = NULL;
    }
    return SUCCESS;
}