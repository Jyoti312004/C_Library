#include<stddef.h>
#include<stdio.h>
#include "generic_sort.h"



// int compare_int(const void *a, const void *b) {
//     int int_a = *((int *)a);
//     int int_b = *((int *)b);
    
//     if (int_a < int_b) return -1;
//     if (int_a > int_b) return 1;
//     return 0;
// }

// // Generic comparison function for doubles
// int compare_double(const void *a, const void *b) {
//     double double_a = *((double *)a);
//     double double_b = *((double *)b);
    
//     if (double_a < double_b) return -1;
//     if (double_a > double_b) return 1;
//     return 0;
// }

// // Generic comparison function for characters
// int compare_char(const void *a, const void *b) {
//     char char_a = *((char *)a);
//     char char_b = *((char *)b);
    
//     if (char_a < char_b) return -1;
//     if (char_a > char_b) return 1;
//     return 0;
// }

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
// void* searching(const void* arr, size_t total_size, size_t size, const void* key, int (*compar)(const void*, const void*)) {
//     int ans = -1;
//     int flag = 0;
//     size_t n = total_size;

//     for (size_t i = 0; i < n - 1; i++) {
//         if (compar((char*)arr + i * size, (char*)arr + (i + 1) * size) > 0) {
//             flag = 1;
//             break;
//         }
//     }

//     if (flag) {
//         return binary_search(arr, n, size, key, compar);
//     } else {
//         return linear_search(arr, n, size, key, compar);
//     }
// } 

void* searching(const void* arr, size_t total_size, size_t size, const void* key, int (*compar)(const void*, const void*)) {
    int isSorted = 1;
    size_t n = total_size;

    for (size_t i = 0; i < n - 1; i++) {
        if (compar((char*)arr + i * size, (char*)arr + (i + 1) * size) > 0) {
            isSorted = 0;
            break; // Array is not sorted
        }
    }

    if (isSorted) {
        return binary_search(arr, n, size, key, compar);
    } else {
        return linear_search(arr, n, size, key, compar);
    }
}


