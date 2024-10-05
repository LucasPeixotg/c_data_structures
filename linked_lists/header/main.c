#include "linked_list.h"
#include <stdio.h>

int main(void) {
    struct linked_list list;
    list.head = NULL;
    list.size = 0;

    push_back(&list, 14, 1);
    push_back(&list, 51, 1);
    push_back(&list, 18, 1);
    push_back(&list, 2, 1);
    push_back(&list, 51, 1);
    push_back(&list, 51, 1);
    push_back(&list, 12, 1);

    printf("\nLIST    : ");
    print_list(&list); 
}