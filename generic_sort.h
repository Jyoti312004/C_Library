
#include <stdlib.h>
#include <string.h>

// Generic swap function
void swap(void* a, void* b, size_t size);
// Generic comparison function
// int (*CompareFn)(const void *a, const void *b);
int compare_int(const void *a, const void *b);
int compare_double(const void *a, const void *b);
int compare_char(const void *a, const void *b);
// Generic selection sort
void selection_sort(void* arr, size_t total_size, size_t size, int (*compar)( const void*,const void*));
// Generic bubble sort
void bubble_sort(void* base, size_t total_size, size_t size, int (*compar)(const void*, const void*));
// Generic insertion sort
void insertion_sort(void* base, size_t total_size, size_t size, int (*compar)(const void*, const void*));
// Generic quick sort
void quick_sort(void* base, size_t total_size, size_t size, int (*compar)(const void*, const void*));
// Generic merge sort
void merge_sort(void* base, size_t total_size, size_t size, int (*compar)(const void*, const void*));
// Generic sorting
void sorting(void* arr, size_t total_size, size_t size, int (*compar)(const void*, const void*));


