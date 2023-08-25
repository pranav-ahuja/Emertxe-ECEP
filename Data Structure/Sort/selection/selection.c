#include "main.h"

data_t selection(data_t *arr, data_t size )
{
    int temp, minimum, min_ind;

    for(int i = 0; i < size; i++)
    {
        min_ind = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[min_ind])
            {                
                min_ind = j;
            }
        }
        if(min_ind != i)
        {
            temp = arr[min_ind];
            arr[min_ind] = arr[i];
            arr[i] = temp;
        }
    }
}
