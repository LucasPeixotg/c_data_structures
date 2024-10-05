#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"

int main(void) {
    struct node* head;
    head = NULL;

    linked_add(&head, 2);
    linked_add(&head, 1);
    linked_append(&head, 3);
    printf("PUSH:\n");
    printf("expected: 1->2->3->\n");
    printf("result  : ");
    linked_print(&head);

    linked_insert(&head, 1, 99);
    linked_insert(&head, 100, 88);
    printf("\nINSERT:\n");
    printf("expected: 1->99->2->3->88->\n");
    printf("result  : ");
    linked_print(&head);

    struct node* copy = copy_list(&head);
    printf("\nCOPY:\n");
    printf("expected: ");
    linked_print(&head);
    printf("result  : ");
    linked_print(&copy);

    linked_pop(&head);
    linked_pop(&head);
    linked_pop(&head);
    linked_pop(&head);
    printf("\nPOP:\n");
    printf("expected: 1->\n");
    printf("result  : ");
    linked_print(&head);

    printf("\nCOPY:\n");
    printf("expected: 1->99->2->3->88->\n");
    printf("result  : ");
    linked_print(&copy);
    
    printf("\nTO ARRAY:\n");
    int* vector = to_array(&copy);
    printf("expected: 1 99 2 3 88\n");
    printf("result  : %d %d %d %d %d\n", vector[0], vector[1], vector[2], vector[3], vector[4]);

    free(vector);
    destroy(head);
    destroy(copy);
}