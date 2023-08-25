#include"hash.h"

int delete_element(hash_t *arr, int data, int size)
{
    int index = data % size;

    hash_t *temp = &arr[index], *next, *temp1;

    if(arr[index].value == data && arr[index].link == NULL)
    {
        arr[index].value = -1;
        return SUCCESS;
    }
    else{        
        while(temp != NULL)
        {
            temp1 = temp->link;
            if(temp1->value == data)
            {
                temp1->value = -1;
                temp->link = temp->link;
                free(temp1);  
                return SUCCESS;              
            }
            temp = temp->link;            
        }
    }
    return DATA_NOT_FOUND;
}