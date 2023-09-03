#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void swap(void *a, void *b, size_t size)
{
    char *temp = malloc(size);
    if (temp == NULL)
    {
        return;
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

// int (*CompareFn)(const void *, const void *);

int compare_int(const void *a, const void *b)
{
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a < int_b)
        return -1;
    if (int_a > int_b)
        return 1;
    return 0;
}

// function for doubles
int compare_double(const void *a, const void *b)
{
    double double_a = *((double *)a);
    double double_b = *((double *)b);

    if (double_a < double_b)
        return -1;
    if (double_a > double_b)
        return 1;
    return 0;
}

//function for characters
int compare_char(const void *a, const void *b)
{
    char char_a = *((char *)a);
    char char_b = *((char *)b);

    if (char_a < char_b)
        return -1;
    if (char_a > char_b)
        return 1;
    return 0;
}

// ***************selection sort ************************

void selection_sort(void *arr, size_t total_size, size_t size, int (*compar)(const void *, const void *))
{

    for (size_t i = 0; i < total_size - 1; i++)
    {
        size_t min_index = i;

        for (size_t j = i + 1; j < total_size; j++)
        {

            if (compar((char *)arr + j * size, (char *)arr + min_index * size) < 0)
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap((char *)arr + i * size, (char *)arr + min_index * size, size);
        }
    }
}

// ***********************bubble sort *************************

void bubble_sort(void *base, size_t total_size, size_t size, int (*compar)(const void *, const void *))
{
    for (size_t i = 0; i < total_size - 1; i++)
    {

        for (size_t j = 0; j < total_size - i - 1; j++)
        {

            void *current = (char *)base + j * size;

            void *next = (char *)base + (j + 1) * size;

            if (compar(current, next) > 0)
            {

                swap(current, next, size);
            }
        }
    }
}

// ***********************insertion sort **********************
void insertion_sort(void *base, size_t total_size, size_t size, int (*compar)(const void *, const void *))
{
    char *array = base;

    for (size_t i = 1; i < total_size; i++)
    {
        size_t j = i;
        while (j > 0 && compar(array + j * size, array + (j - 1) * size) < 0)
        {
            swap(array + j * size, array + (j - 1) * size, size);
            j--;
        }
    }
}

// ***********************quick sort ************************

int partition(void *base, int low, int high, size_t size, int (*compar)(const void *, const void *))
{
    void *pivot = (char *)base + high * size;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        void *current = (char *)base + j * size;
        if (compar(current, pivot) <= 0)
        {
            i++;
            swap((char *)base + i * size, (char *)base + j * size, size);
        }
    }
    swap((char *)base + (i + 1) * size, (char *)base + high * size, size);
    return i + 1;
}

void quicksort(void *base, int low, int high, size_t size, int (*compar)(const void *, const void *))
{
    if (low < high)
    {
        int pivot_index = partition(base, low, high, size, compar);

        quicksort(base, low, pivot_index - 1, size, compar);

        quicksort(base, pivot_index + 1, high, size, compar);
    }
}

void quick_sort(void *base, size_t total_size, size_t size, int (*compar)(const void *, const void *))
{
    quicksort(base, 0, total_size - 1, size, compar);
}

//*************************merge sort *********************

void merge(void *base, int left, int mid, int right, size_t size, int (*compar)(const void *, const void *))
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    void *temp_left = malloc(size * n1);
    void *temp_right = malloc(size * n2);

    if (!temp_left || !temp_right)
    {
        free(temp_left);
        free(temp_right);
        return;
    }

    memcpy(temp_left, (char *)base + left * size, size * n1);
    memcpy(temp_right, (char *)base + (mid + 1) * size, size * n2);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        void *left_elem = (char *)temp_left + i * size;
        void *right_elem = (char *)temp_right + j * size;

        if (compar(left_elem, right_elem) <= 0)
        {
            memcpy((char *)base + k * size, left_elem, size);
            i++;
        }
        else
        {
            memcpy((char *)base + k * size, right_elem, size);
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        void *left_elem = (char *)temp_left + i * size;
        memcpy((char *)base + k * size, left_elem, size);
        i++;
        k++;
    }

    while (j < n2)
    {
        void *right_elem = (char *)temp_right + j * size;
        memcpy((char *)base + k * size, right_elem, size);
        j++;
        k++;
    }

    free(temp_left);
    free(temp_right);
}


void mergesort(void *base, int left, int right, size_t size, int (*compar)(const void *, const void *))
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(base, left, mid, size, compar);
        mergesort(base, mid + 1, right, size, compar);
        merge(base, left, mid, right, size, compar);
    }
}
void merge_sort(void *base, size_t total_size, size_t size, int (*compar)(const void *, const void *))
{
    mergesort(base, 0, total_size - 1, size, compar);
}


