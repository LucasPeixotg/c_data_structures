#include "linked_list.h"
#include <malloc.h>

/**
 * @brief Inserts a new node with a given value at the beginning of the list.
 * 
 * @param head_ref A pointer to the head of the list.
 * @param value The value to be inserted in the new node.
 */
void linked_add(struct node** node_ref, int value) {
    // Note, the reference passed can be a node at any given position of the list
    struct node* new = malloc(sizeof(struct node));
    new->data = value;
    new->prev = NULL;
    
    if(*node_ref == NULL) {
        *node_ref = new;
        new->next = NULL;
        return;
    }

    struct node* current = *node_ref;
    while(current->prev != NULL) current = current->prev;

    new->next = current;
    current->prev = new;
}

/**
 * @brief Appends a new node with a given value at the end of the list.
 * 
 * @param head_ref A pointer to the head of the list.
 * @param value The value to be inserted in the new node.
 */
void linked_append(struct node** node_ref, int value) {
    // Note, the reference passed can be a node at any given position of the list
    struct node* new = malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;

    if(*node_ref == NULL) {
        *node_ref = new;
        new->prev = NULL;
        return;
    }

    struct node* current = *node_ref;
    while(current->next != NULL) current = current->next;

    new->prev = current;
    current->next = new;
}

/**
 * @brief Removes the first node from the list.
 * 
 * @param head_ref A pointer to the head of the list.
 */
void linked_pop(struct node** node_ref) {
    // Note, the reference passed can be a node at any given position of the list
    if(*node_ref == NULL) return;

    struct node* temp = (*node_ref)->next;
    free(*node_ref);
    
    *node_ref = temp;
}

/**
 * @brief Prints all the elements of the list.
 * 
 * @param head_ref A pointer to the head of the list.
 */
void linked_print(struct node** node_ref) {
    if(*node_ref == NULL) {
        printf("\n");
        return;
    }

    struct node* current = *node_ref;
    // go to the start of the list
    while(current->prev != NULL) current = current->prev;

    printf("<->");
    while(current != NULL) {
        printf("%d<->", current->data);
        current = current->next;
    }
    printf("\n");
}