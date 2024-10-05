#include <malloc.h>
#include "linked_list.h"

/**
 * @brief Inserts a new node with the given value and key at the end of the list.
 * 
 * @param linked_list A pointer to the linked list.
 * @param value The data value to be stored in the new node.
 * @param key The key associated with the new node.
 */
void push_back(struct linked_list* header, int value, int key) {
    struct node* new = malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    new->key = key;
    
    if(header->size == 0) {
        header->head = new;
        header->size++;
        return;
    }

    struct node* current = header->head;
    while(current->next != NULL) current = current->next;

    current->next = new;
    header->size++;
}

/**
 * @brief Inserts a new node with the given value and key at the beginning of the list.
 * 
 * @param header A pointer to the linked list.
 * @param value The data value to be stored in the new node.
 * @param key The key associated with the new node.
 */
void push_front(struct linked_list* header, int value, int key) {
    struct node* new = malloc(sizeof(struct node));
    new->data = value;

    new->next = header->head;
    header->head = new;
    header->size++;
    new->key = key;
}

/**
 * @brief Removes the last node from the list.
 * 
 * @param header A pointer to the linked list.
 */
void pop_back(struct linked_list* header) {
    if(header->head == NULL) return;
    if(header->head->next == NULL) {
        free(header->head);
        header->head = NULL;
        header->size--;
        return;
    }

    struct node* current = header->head;
    while(current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    header->size--;
}

/**
 * @brief Removes the first node from the list.
 * 
 * @param header A pointer to the linked list.
 */
void pop_front(struct linked_list* header) {
    if(header->head != NULL) {
        struct node* next = header->head->next;
        free(header->head);
        header->head = next;
        header->size--;
    }
}

/**
 * @brief Prints all elements of the list.
 * 
 * @param header A pointer to the linked list.
 */
void print_list(struct linked_list* header) {
    struct node* current = header->head;
    while(current != NULL) {
        printf("[%d] %d -> ", current->key, current->data);
        current = current->next;
    }
    printf("\n");
}

/**
 * @brief Adds an offset to the data value of a node based on its key.
 * 
 * @param header A pointer to the linked list.
 * @param key The key of the node to modify.
 * @param offset The value to be added to the node's data.
 * 
 * @return The new data value after adding the offset, or -1 if the key is not found.
 */
int add_offset_by_key(struct linked_list* header, int key, int offset) {
    if(header->head == NULL) return 1;

    struct node** previous = &(header->head);
    struct node* current = header->head;

    int i = 0;
    while(current != NULL) {
        if(current->key == key) break;
        if(i >= offset) previous = &((*previous)->next);
        current = current->next;
        i++;
    }

    if(current == NULL) return 1;

    struct node* new = malloc(sizeof(struct node));
    new->data = current->data;
    new->key = key;

    new->next = *previous;
    *previous = new;

    return 0;
}

/**
 * @brief Removes all odd-valued nodes that are between even-valued nodes in the list.
 * 
 * @param header A pointer to the linked list.
 * 
 * @return The number of nodes removed from the list.
 */
int remove_odds_between_evens(struct linked_list* header) {
    struct node* current = header->head;
    if(current->next == NULL && current->data % 2 == 1) {
        free(current);
        header->head = NULL;
        return;
    }

    int odd_found = 0;
    int event_found = 0;
    while(current != NULL) {
        if(current->next && current->next->data % 2 == 1) {
            if(event_found) {
                struct node* next = current->next->next;
                free(current->next);
                current->next = next;
                odd_found = 1;
                continue;
            }
        } else {
            if(odd_found) break;
            event_found = 1;
        };
        current = current->next;
    }
}