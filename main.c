#include <stdio.h>
#include "generic_sort.h"
#include "c_basic.h"
#include "searching.h"

int main()
{
    // JYOTI
    int elementDataType;
    size_t element_size;

    printf("Select element data type:\n");
    printf("1. int\n");
    printf("2. double\n");
    printf("3. char\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &elementDataType);
    int (*CompareFn)(const void *a, const void *b);

    switch (elementDataType)
    {
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
    for (size_t i = 0; i < arraySize; i++)
    {
        if (elementDataType == 1)
        {
            int ele;
            scanf("%d", &ele);
            *((int *)(userArray + i * element_size)) = ele;
        }
        else if (elementDataType == 2)
        {
            double ele;
            scanf("%lf", &ele);
            *((double *)(userArray + i * element_size)) = ele;
        }
        else if (elementDataType == 3)
        {
            char ele;
            scanf(" %c", &ele);
            *((char *)(userArray + i * element_size)) = ele;
        }
    }
    printf("\n");
    const void *key = NULL;

    if (elementDataType == 1)
    {
        int value;
        printf("Enter an integer key: ");
        scanf("%d", &value);
        key = &value;
    }
    else if (elementDataType == 2)
    {
        double value;
        printf("Enter a double key: ");
        scanf("%lf", &value);
        key = &value;
    }
    else if (elementDataType == 3)
    {
        char value;
        printf("Enter a character key: ");
        scanf(" %c", &value);
        key = &value;
    }
    else
    {
        printf("Invalid data type.\n");
        return 1;
    }

    if (searching(userArray, arraySize, element_size, key, CompareFn))
    {
        
        if (elementDataType == 1)
        {
            printf("Key %d is present\n", *((int *)key));
        }
        else if (elementDataType == 2)
        {
            printf("Key %.2lf is present\n", *((double *)key));
        }
        else if (elementDataType == 3)
        {
            printf("Key %c is present\n", *((char *)key));
        }
    }
    else
    {
        printf("Key is not present\n");
    }

    if (elementDataType == 1 || elementDataType == 2 || elementDataType == 3)
    {
        quick_sort(userArray, arraySize, element_size, CompareFn);

        printf("\nSorted array: ");
        for (size_t i = 0; i < arraySize; i++)
        {
            if (elementDataType == 1)
            {
                printf("%d ", *((int *)(userArray + i * element_size)));
            }
            else if (elementDataType == 2)
            {
                printf("%.2lf ", *((double *)(userArray + i * element_size)));
            }
            else if (elementDataType == 3)
            {
                printf("%c ", *((char *)(userArray + i * element_size)));
            }
        }
        printf("\n");
    }

    printf("\nMaximum element of the array\n");
    void *max = NULL;
    if (elementDataType == 1)
    {
        max = maxi(userArray, arraySize, element_size, compare_int);
        printf("%d is the maximum element \n", (*(int *)max));
    }
    else if (elementDataType == 2)
    {
        max = maxi(userArray, arraySize, element_size, compare_double);
        printf("%.2lf is the maximum element \n", (*(double *)max));
    }
    else if (elementDataType == 3)
    {
        max = maxi(userArray, arraySize, element_size, compare_char);
        printf("%c is the maximum element \n", (*(char *)max));
    }
    else
    {
        printf("Invalid data type.\n");
        return 1;
    }

    printf("\nMinimum element of the array\n");
    void *min = NULL;
    if (elementDataType == 1)
    {
        min = mini(userArray, arraySize, element_size, compare_int);
        printf("%d is the minium element \n", (*(int *)min));
    }
    else if (elementDataType == 2)
    {
        min = mini(userArray, arraySize, element_size, compare_double);
        printf("%.2lf is the minium element \n", (*(double *)min));
    }
    else if (elementDataType == 3)
    {
        min = mini(userArray, arraySize, element_size, compare_char);
        printf("%c is the minium element \n", (*(char *)min));
    }
    else
    {
        printf("Invalid data type.\n");
        return 1;
    }

    free(userArray);

    return 0;
}
