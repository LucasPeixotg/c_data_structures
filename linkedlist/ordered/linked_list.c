#include <malloc.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

void add(struct node** head, int value) {
    if(*head == NULL) {
        *head = malloc(sizeof(struct node));
        (*head)->data = value;
        (*head)->next = NULL;
        return;
    }
    if((*head)->data > value) {
        struct node* new = malloc(sizeof(struct node));
        new->data = value;
        new->next = (*head);

        (*head) = new;
        return;
    }

    struct node* current = *head;
    while(current->next != NULL && current->next->data < value) current = current->next;
    
    struct node* new = malloc(sizeof(struct node));
    new->data = value;
    new->next = current->next;
    current->next = new;
}

void print_list(struct node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("\n");
}