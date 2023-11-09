#include <stdio.h>
#include "linked_list.h"

int main(void) {
    struct node* head = NULL;

    add(&head, 6);
    add(&head, 1);
    add(&head, 3);
    add(&head, 7);
    add(&head, 9);
    add(&head, 17);
    
    print_list(head);
}