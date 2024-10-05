#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int data;         // The data value of the node
    int key;          // The key associated with the node
    struct node* next;  // Pointer to the next node
};

struct linked_list {
    int size;         // Number of nodes in the list
    struct node* head;  // Pointer to the first node in the list
};

/**
 * @brief Inserts a new node with the given value and key at the end of the list.
 * 
 * @param linked_list A pointer to the linked list.
 * @param value The data value to be stored in the new node.
 * @param key The key associated with the new node.
 */
void push_back(struct linked_list* linked_list, int value, int key);

/**
 * @brief Inserts a new node with the given value and key at the beginning of the list.
 * 
 * @param header A pointer to the linked list.
 * @param value The data value to be stored in the new node.
 * @param key The key associated with the new node.
 */
void push_front(struct linked_list* header, int value, int key);

/**
 * @brief Removes the last node from the list.
 * 
 * @param header A pointer to the linked list.
 */
void pop_back(struct linked_list* header);

/**
 * @brief Removes the first node from the list.
 * 
 * @param header A pointer to the linked list.
 */
void pop_front(struct linked_list* header);

/**
 * @brief Prints all elements of the list.
 * 
 * @param header A pointer to the linked list.
 */
void print_list(struct linked_list* header);

/**
 * @brief Adds an offset to the data value of a node based on its key.
 * 
 * @param header A pointer to the linked list.
 * @param key The key of the node to modify.
 * @param offset The value to be added to the node's data.
 * 
 * @return The new data value after adding the offset, or -1 if the key is not found.
 */
int add_offset_by_key(struct linked_list* header, int key, int offset);

#endif