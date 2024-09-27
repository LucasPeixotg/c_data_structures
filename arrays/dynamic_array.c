#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Dynamic_Array
{
    int *element;  // Pointer to the integer array
    size_t size;  // Size of the array
    size_t count;  // Number of elements that are currently in the array

    // Function to add an element
    void (*add)(struct Dynamic_Array (*array), int value);

    // Function to remove an element
    void (*remove)(struct Dynamic_Array (*array), size_t index);

    // Function to modify an element
    void (*alter)(struct Dynamic_Array (*array), size_t index, int value);

    // Function to free memory
    void (*free)(struct Dynamic_Array (*array));

} list;

// Functions for manipulating the list
void add_element(list (*array), int value) 
{
    if (array->count < array->size) 
    {
        array->element[array->count++] = value;
    } 
    else 
    {
        // Logic to increase the size of the array if necessary
        size_t new_size = array->size * 2;
        array->element = (int *)realloc(array->element, new_size * sizeof(int));
        if (array->element) 
        {
            array->size = new_size;
            array->element[array->count++] = value;
        } 
        else 
        {
            fprintf(stderr, "Memory reallocation error.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void remove_element(list (*array), size_t index) 
{
    if (index < array->count) 
    {
        for (size_t i = index; i < array->count - 1; i++) 
        {
            array->element[i] = array->element[i + 1];
        }
        array->count--;
    }
}

void alter_element(list (*array), size_t index, int value) 
{
    if (index < array->count) 
    {
        array->element[index] = value;
    }
}

//Function to free the allocated memory.
void free_array(list (*array)) 
{
    free(array->element);
    array->element = NULL; // To avoid dangling pointers
    array->count = 0;
    array->size = 0;
}

#endif // DYNAMICARRAY_H
