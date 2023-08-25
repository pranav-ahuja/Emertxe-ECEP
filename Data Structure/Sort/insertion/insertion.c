#include "main.h"

data_t insertion(data_t *arr, data_t size)
{
    int j, temp, data;
    for(int i = 1; i < size; i++)
    {
        data = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > data)
        {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;

            j--;
        }

    }
}
