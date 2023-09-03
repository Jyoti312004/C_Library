#include<stddef.h>
#include<stdio.h>
#include "generic_sort.h"

// A generic function for linear search 
void* linear_search(const void* arr, size_t total_size, size_t size, const void* target, int (*compar)(const void*, const void*)) {
  
    const char* base = arr;


    for (size_t i = 0; i < total_size; i++) {

        void* current = (void*)(base + i * size);
        
        if (compar(current, target) == 0) {
            return current; 
        }
    }

    return NULL;
}

// A generic function for binary search ( it works for only sorted array)
void* binary_search(const void* arr, size_t total_size, size_t size, const void* target, int (*compar)(const void*, const void*)) {
   // printf("inside binary");
    const char* base = arr;
    size_t low = 0;
    size_t high = total_size - 1;

    while (low <= high) {
       //   printf("inside binary");
        size_t mid = low + (high - low) / 2;
        void* mid_element = (void*)(base + mid * size);
        int result = compar(mid_element, target);

        if (result == 0) {
            return mid_element;
        } else if (result < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return NULL; 
    
}

// searching function will check whether the array is sorted or not 
// if sorted then it use binary search otherwise linear search 
void* searching(const void* arr, size_t total_size, size_t size, const void* key, int (*compar)(const void*, const void*)) {
    int isSorted = 1;
    size_t n = total_size;

    for (size_t i = 0; i < n - 1; i++) {
        if (compar((char*)arr + i * size, (char*)arr + (i + 1) * size) > 0) {
            // if the array is not sorted it will break 
            isSorted = 0;
            break;
        }
    }

    if (isSorted) {
        return binary_search(arr, n, size, key, compar);
    } else {
        return linear_search(arr, n, size, key, compar);
    }
}


