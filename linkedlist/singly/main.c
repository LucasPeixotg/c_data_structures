#include <stdio.h>
#include "linked_list.h"

int main(void) {
    struct node* head;
    head = NULL;

    insert_beggining(&head, 2);
    insert_beggining(&head, 1);
    append(&head, 3);
    printf("PUSH:\n");
    printf("expected: 1->2->3->\n");
    printf("result  : ");
    printList(&head);

    insert(&head, 1, 99);
    insert(&head, 100, 88);
    printf("\nINSERT:\n");
    printf("expected: 1->99->2->3->88->\n");
    printf("result  : ");
    printList(&head);

    struct node* copy = copy_list(&head);
    printf("\nCOPY:\n");
    printf("expected: ");
    printList(&head);
    printf("result  : ");
    printList(&copy);

    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    printf("\nPOP:\n");
    printf("expected: 1->\n");
    printf("result  : ");
    printList(&head);

    printf("\nCOPY:\n");
    printf("expected: 1->99->2->3->88->\n");
    printf("result  : ");
    printList(&copy);
    
    printf("\nTO ARRAY:\n");
    int* vector = to_array(&copy);
    printf("expected: 1 99 2 3 88\n");
    printf("result  : %d %d %d %d %d\n", vector[0], vector[1], vector[2], vector[3], vector[4]);
}