#include"hash.h"

int search_HT(hash_t *arr, int data, int size)
{   
    //logic to check if the list is empty
    int is_list_empty = 1;
    for(int i = 0; i<size; i++)
    {
        if(arr[i].value != -1)
        {
            is_list_empty = 0;
            break;
        }    
    }
    if(is_list_empty == 1)
        return LIST_EMPTY;

    int index = data % size;

    //logic to search the element
    hash_t *temp = &arr[index];

    while(temp != NULL)
    {
        if(temp->value == data)
        {
            return SUCCESS;
        }
    }
    return DATA_NOT_FOUND;
    
}