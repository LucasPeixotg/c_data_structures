#include "linked_list.h"
#include <stdio.h>

int main(void) {
    struct linked_list list;
    list.head = NULL;
    list.size = 0;

    push(&list, 51, 1);
    push(&list, 51, 1);
    push(&list, 51, 1);
    push(&list, 2, 1);
    push(&list, 51, 1);
    push(&list, 51, 1);
    push(&list, 51, 1);

    printf("\nLIST    : ");
    print_list(&list);
    remove_odds_between_even(&list);
    printf("expected: [1] 51 -> [1] 51 -> [1] 51 -> [1] 2 -> \n");
    printf("result  : ");
    print_list(&list);    
}