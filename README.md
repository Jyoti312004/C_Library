# C Library for Sorting and Searching

## Introduction

This C library provides a versatile set of sorting and searching algorithms designed to be generic and customizable through function pointers. Whether you're working with integers, doubles, or characters, this library offers powerful tools to sort and search data efficiently.

## Features

### Sorting Algorithms

- **Bubble Sort:** A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
  
- **Quick Sort:** A divide-and-conquer sorting algorithm that works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.

- **Merge Sort:** Another divide-and-conquer sorting algorithm that divides the unsorted list into n sub-lists, each containing one element, and then repeatedly merges sub-lists to produce new sorted sub-lists until there is only one sub-list remaining.

- **Insertion Sort:** A simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

- **Selection Sort:** A simple sorting algorithm that divides the input list into two parts: a sorted sublist and an unsorted sublist. It repeatedly selects the minimum element from the unsorted sublist and moves it to the end of the sorted sublist.

### Searching Algorithms

- **Linear Search:** A basic searching algorithm that iterates through an array to find a specific element. It is simple but not the most efficient for large datasets.

- **Binary Search:** An efficient searching algorithm that works on sorted arrays. It repeatedly divides the search interval in half until the target element is found or the interval is empty.

### Generic Functions

- `swap`: A generic function for swapping two elements of any data type, making it easy to sort and manipulate data.

- `min`: A generic function to find the minimum element in an array of any data type.

- `max`: A generic function to find the maximum element in an array of any data type.

## How to Use

1. Include the library headers in your C code:
   - `#include "generic_sort.h"` for sorting algorithms and generic functions.
   - `#include "searching.h"` for searching algorithms.
   - `#include "c_basic.h"` for basic generic functions like `swap`, `min`, and `max`.

2. Define your comparison functions:
   - For sorting algorithms, you'll need to define comparison functions tailored to your data types. Examples for integer, double, and character data types are provided.

3. Initialize your array of data and function pointers.
   - You can create arrays of different data types (e.g., int, double, char).
   - Initialize function pointers with the appropriate comparison function.

4. Use the sorting and searching functions provided in the library with your data.

## Example Usage

Here's an example of how to use the library to sort and search for elements:

```c
#include <stdio.h>
#include "generic_sort.h"
#include "c_basic.h"
#include "searching.h"

int main() {
    // Initialize your data, function pointers, and perform sorting and searching here.
    
    // Example sorting:
    int intArray[5] = {5, 3, 1, 4, 2};
    size_t arraySize = sizeof(intArray) / sizeof(intArray[0]);
    int (*CompareFn)(const void *a, const void *b) = compare_int;
    bubble_sort(intArray, arraySize, sizeof(int), CompareFn);
    
    // Example searching:
    int target = 3;
    int *found = binary_search(intArray, arraySize, sizeof(int), &target, CompareFn);
    
    if (found != NULL) {
        printf("Found: %d\n", *found);
    } else {
        printf("Not found.\n");
    }
    
    return 0;
}
