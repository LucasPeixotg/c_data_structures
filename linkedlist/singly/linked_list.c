#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node* next;
};

/*
Insert in the beggining of the list
*/
void insert_beggining(struct node** head_ref, int value) {
    struct node* new = malloc(sizeof(struct node));

    new->data = value;
    new->next = *head_ref;

    *head_ref = new;
}

/*
Insert in the end of the list
*/
void append(struct node** head_ref, int value) {
    struct node* new = malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;

    if(*head_ref == NULL) {
        *head_ref = new;
        return;
    }

    struct node* current = *head_ref;
    while(current->next != NULL) current = current->next;

    current->next = new;
}

/*
Insert at an specific index, 
or in the end, if the list is smaller than necessary
*/
void insert(struct node** head_ref, int index, int value) {
    struct node* new = malloc(sizeof(struct node));
    new->data = value;
    
    if(*head_ref == NULL || index == 0) {
        *head_ref = new;
        new->next = NULL;
        return;
    }

    struct node* current = *head_ref;
    for(int i = 0; i < index - 1; i++) {
        if(current->next == NULL) break;
        current = current->next;
    }

    new->next = current->next;
    current->next = new;
}

/*
Remove the last node of the list
*/
void pop(struct node** head_ref) {
    struct node* current = *head_ref;
    if(current == NULL) return;
    if(current->next == NULL) {
        free(current);
        *head_ref = NULL;
    }
    
    while(current->next->next != NULL) current = current->next;

    free(current->next);
    current->next = NULL;
}

/*
Returns a copy of the list
*/
struct node* copy_list(struct node** head_ref) {
    struct node* copy = NULL;

    if(head_ref == NULL) return copy;

    struct node* current = *head_ref;
    while(current != NULL) {
        append(&copy, current->data);
        current = current->next;
    }

    return copy;
}

int* to_array(struct node** head_ref) {
    if(head_ref == NULL) return NULL;

    struct node* current = *head_ref;
    int size = 0;
    while(current != NULL) {
        size++;
        current = current->next;
    }

    int* vector = malloc(size * sizeof(int));
    current = *head_ref;
    for(int i = 0; i < size; i++) {
        vector[i] = current->data;
        current = current->next;
    }

    return vector;
}

/*
Prints all elements of the list
*/
void printList(struct node** head_ref) {
    struct node* current = *head_ref;

    while(current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}
