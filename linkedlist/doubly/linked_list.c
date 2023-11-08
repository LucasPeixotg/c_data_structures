#include <malloc.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

/*
Insert in the beggining of the list
*/
void insert_beggining(struct node** node_ref, int value) {
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

/*
Insert in the end of the list
*/
void append(struct node** node_ref, int value) {
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

/*
Remove the last node of the list
*/
void pop(struct node** node_ref) {
    // Note, the reference passed can be a node at any given position of the list
    if(*node_ref == NULL) return;

    struct node* current = *node_ref;
    while(current->next != NULL) current = current->next;

    if(current->prev != NULL) current->prev->next = NULL;
    *node_ref = current->prev;
    free(current);
}

/*
Prints all elements of the list
*/
void printList(struct node** node_ref) {
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