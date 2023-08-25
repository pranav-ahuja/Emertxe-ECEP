#include "main.h"

/* Function to partition the array */
int partition(int *arr, int first, int last)
{
    int pivot = arr[last];
    int temp;
     
    int i = (first - 1);
 
    for (int j = first; j <= last - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
 
            // Increment index of smaller element
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[last];
    arr[last] = temp;
    
    return (i + 1);
}
