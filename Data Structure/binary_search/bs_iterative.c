#include "main.h"

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    int low = 0, high = size - 1, mid;

    while(low < high)
    {
        mid = (low + high)/2;
        if(key < arr[mid])
        {
            high = mid - 1;
        }
        else if(key > arr[mid])
        {
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return DATA_NOT_FOUND;
}
