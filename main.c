#include <stdio.h>
#include<time.h>
#include "generic_sort.h"
#include "c_basic.h"
#include "searching.h"

int main()
{
    clock_t start,end;
    double cpu_time;
    int DataType;
    size_t element_size;
    start = clock();
    printf("Enter the data type of an element :\n");
    printf("1. Integer \n");
    printf("2. Double \n");
    printf("3. Character \n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &DataType);
    int (*Compare)(const void *a, const void *b);

    switch (DataType)
    {
    case 1:
        element_size = sizeof(int);
        Compare = compare_int;
        break;
    case 2:
        element_size = sizeof(double);
        Compare = compare_double;
        break;
    case 3:
        element_size = sizeof(char);
        Compare = compare_char;
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
        if (DataType == 1)
        {
            int ele;
            scanf("%d", &ele);
            *((int *)(userArray + i * element_size)) = ele;
        }
        else if (DataType == 2)
        {
            double ele;
            scanf("%lf", &ele);
            *((double *)(userArray + i * element_size)) = ele;
        }
        else if (DataType == 3)
        {
            char ele;
            scanf(" %c", &ele);
            *((char *)(userArray + i * element_size)) = ele;
        }
    }
    printf("\n");
    const void *key = NULL;

    if (DataType == 1)
    {
        int value;
        printf("Enter an integer key: ");
        scanf("%d", &value);
        key = &value;
    }
    else if (DataType == 2)
    {
        double value;
        printf("Enter a double key: ");
        scanf("%lf", &value);
        key = &value;
    }
    else if (DataType == 3)
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

    if (searching(userArray, arraySize, element_size, key, Compare))
    {
        
        if (DataType == 1)
        {
            printf("Key %d is present\n", *((int *)key));
        }
        else if (DataType == 2)
        {
            printf("Key %.2lf is present\n", *((double *)key));
        }
        else if (DataType == 3)
        {
            printf("Key %c is present\n", *((char *)key));
        }
    }
    else
    {
        printf("Key is not present\n");
    }

    printf("\nMaximum element of the array\n");
    void *max = NULL;
    if (DataType == 1)
    {
        max = maxi(userArray, arraySize, element_size, compare_int);
        printf("%d is the maximum element \n", (*(int *)max));
    }
    else if (DataType == 2)
    {
        max = maxi(userArray, arraySize, element_size, compare_double);
        printf("%.2lf is the maximum element \n", (*(double *)max));
    }
    else if (DataType == 3)
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
    if (DataType == 1)
    {
        min = mini(userArray, arraySize, element_size, compare_int);
        printf("%d is the minimum element \n", (*(int *)min));
    }
    else if (DataType == 2)
    {
        min = mini(userArray, arraySize, element_size, compare_double);
        printf("%.2lf is the minimum element \n", (*(double *)min));
    }
    else if (DataType == 3)
    {
        min = mini(userArray, arraySize, element_size, compare_char);
        printf("%c is the minimum element \n", (*(char *)min));
    }
    else
    {
        printf("Invalid data type.\n");
        return 1;
    }

    if (DataType == 1 || DataType == 2 || DataType == 3)
    {
        quick_sort(userArray, arraySize, element_size, Compare);

        printf("\nSorted array: ");
        for (size_t i = 0; i < arraySize; i++)
        {
            if (DataType == 1)
            {
                printf("%d ", *((int *)(userArray + i * element_size)));
            }
            else if (DataType == 2)
            {
                printf("%.2lf ", *((double *)(userArray + i * element_size)));
            }
            else if (DataType == 3)
            {
                printf("%c ", *((char *)(userArray + i * element_size)));
            }
        }
        printf("\n");
    }


    free(userArray);

    end = clock();
    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\n");
    printf("CPU Time Used: %f seconds \n",cpu_time);
    printf("\n");

    return 0;
}
