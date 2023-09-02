#include <stdio.h>
#include "generic_sort.h"
#include "c_basic.h"
#include "searching.h"

int main() {
    // JYOTI
    int elementDataType;
    size_t element_size;

    printf("Select element data type:\n");
    printf("1. int\n");
    printf("2. double\n");
    printf("3. char\n");
    printf("Enter your choice: ");
    scanf("%d", &elementDataType);
    int (*CompareFn)(const void *a, const void *b);

    switch (elementDataType) {
        case 1:
            element_size = sizeof(int);
            CompareFn = compare_int;
            break;
        case 2:
            element_size = sizeof(double);
            CompareFn = compare_double;
            break;
        case 3:
            element_size = sizeof(char);
            CompareFn = compare_char;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    int arraySize;
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

  
    void *userArray = malloc(element_size * arraySize);

    printf("Enter the elements of the array separated by spaces:\n");
    for (size_t i = 0; i < arraySize; i++) {
        if (elementDataType == 1) {
            int ele;
            scanf("%d", &ele);
            *((int *)(userArray + i * element_size)) = ele;
        } else if (elementDataType == 2) {
            double ele;
            scanf("%lf", &ele);
            *((double *)(userArray + i * element_size)) = ele;
        } else if (elementDataType == 3) {
            char ele;
            scanf(" %c", &ele);
            *((char *)(userArray + i * element_size)) = ele;
        }
    }

const void* key = NULL; 

if (elementDataType == 1) { 
    int value;
    printf("Enter an integer key: ");
    scanf("%d", &value);
    key = &value; 
} else if (elementDataType == 2) { 
    double value;
    printf("Enter a double key: ");
    scanf("%lf", &value);
    key = &value;
} else if (elementDataType == 3) { 
    char value;
    printf("Enter a character key: ");
    scanf(" %c", &value);
    key = &value; 
} else {
    printf("Invalid data type.\n");
    return 1;
}


if (searching(userArray, arraySize, element_size, key, CompareFn)) {
    // Key is present, print the value pointed to by key
    if (elementDataType == 1) {
        printf("Key %d is present\n", *((int*)key));
    } else if (elementDataType == 2) {
        printf("Key %.2lf is present\n", *((double*)key));
    } else if (elementDataType == 3) {
        printf("Key %c is present\n", *((char*)key));
    }
} else {
    printf("Key is not present\n");
}


    if (elementDataType == 1 || elementDataType == 2 || elementDataType == 3) {
        quick_sort(userArray,arraySize, element_size, CompareFn);

        printf("Sorted array: ");
        for (size_t i = 0; i < arraySize; i++) {
            if (elementDataType == 1) {
                printf("%d ", *((int *)(userArray + i * element_size)));
            } else if (elementDataType == 2) {
                printf("%.2lf ", *((double *)(userArray + i * element_size)));
            } else if (elementDataType == 3) {
                printf("%c ", *((char *)(userArray + i * element_size)));
            }
        }
        printf("\n");
    }

    free(userArray);

    return 0;
}