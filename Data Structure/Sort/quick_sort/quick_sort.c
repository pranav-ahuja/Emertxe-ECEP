#include "main.h"

/* Function to sort the array in quick sort method */
int quick_sort( int *arr, int first, int last )
{    
    if (first < last) {
 
        int pi = partition(arr, first, last);
 
        quick_sort(arr, first, pi - 1);
        quick_sort(arr, pi + 1, last);
    }
}
