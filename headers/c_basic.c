#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stddef.h>

void Swap(void* a, void* b, size_t size) {
    char* temp = malloc(size);
    if (temp) {
        memcpy(temp, a, size);
        memcpy(a, b, size);
        memcpy(b, temp, size);
        free(temp);
    }
}

void* mini(const void* arr, size_t total_size, size_t size, int (*compar)(const void*, const void*)) {
    if (total_size == 0) {
        return NULL; 
    }

    const char* base = arr;
    void* min_element = (void*)base;

    for (size_t i = 1; i < total_size; i++) {
        void* current = (void*)(base + i * size);

        if (compar(current, min_element) < 0) {
            min_element = current; 
        }
    }

    return min_element;
}

void* maxi(const void* arr, size_t total_size, size_t size, int (*compar)(const void*, const void*)) {
    if (total_size == 0) {
        return NULL; 
    }

    const char* base = arr;
    void* max_element = (void*)base;

    for (size_t i = 1; i < total_size; i++) {
        void* current = (void*)(base + i * size);

        if (compar(current, max_element) > 0) {
            max_element = current; 
        }
    }

    return max_element;
}

