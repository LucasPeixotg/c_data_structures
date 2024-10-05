#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

/**
 * @brief Inserts a new node with a given value at the beginning of the list.
 * 
 * @param head_ref A pointer to the head of the list.
 * @param value The value to be inserted in the new node.
 */
void linked_add(struct node** head_ref, int value);

/**
 * @brief Appends a new node with a given value at the end of the list.
 * 
 * @param head_ref A pointer to the head of the list.
 * @param value The value to be inserted in the new node.
 */
void linked_append(struct node** head_ref, int value);

/**
 * @brief Inserts a new node with a given value at a specific index in the list.
 *        If the index is out of bounds, the node is appended at the end.
 * 
 * @param head_ref A pointer to the head of the list.
 * @param index The index at which the new node should be inserted.
 * @param value The value to be inserted in the new node.
 */
void linked_insert(struct node** head_ref, int index, int value);

/**
 * @brief Removes the first node from the list.
 * 
 * @param head_ref A pointer to the head of the list.
 */
void linked_pop(struct node** head_ref);

/**
 * @brief Prints all the elements of the list.
 * 
 * @param head_ref A pointer to the head of the list.
 */
void linked_print(struct node** head_ref);

#endif