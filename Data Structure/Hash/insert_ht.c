#include"hash.h"

int insert_HT(hash_t *arr, int element, int size)
{
    //calculate the index
    int index = element % size;

    //check if the value of array node is -1 or not
    if(arr[index].value == -1)
    {
        //assign the value to element
        arr[index].value = element;
    }
    else{
        //else cllocate memory to a new node and check if the memory is alloted or not
        hash_t *new = malloc(sizeof(hash_t));
        if(new == NULL)
        {
            return FAILURE;
        }

        //assign the values to new node
        new->value = element;
        new->index = index;
        new->link = NULL;

        //logic to insert the node
        hash_t *temp = &arr[index];
        while(temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new;        
    }
}