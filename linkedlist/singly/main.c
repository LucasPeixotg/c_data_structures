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

    pop(&head);
    pop(&head);
    pop(&head);
    pop(&head);
    printf("\nPOP:\n");
    printf("expected: 1->\n");
    printf("result  : ");
    printList(&head);
}