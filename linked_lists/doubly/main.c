#include <stdio.h>
#include "linked_list.h"

int main(void) {
    struct node* ref;
    ref = NULL;

    linked_add(&ref, 3);
    linked_add(&ref, 2);
    linked_add(&ref, 1);
    printf("PUSH:\n");
    printf("expected: <->1<->2<->3<->\n");
    printf("result  : ");
    linked_print(&ref);

    linked_append(&ref, 4);
    linked_append(&ref, 5);
    linked_append(&ref, 6);
    printf("PUSH:\n");
    printf("expected: <->1<->2<->3<->4<->5<->6<->\n");
    printf("result  : ");
    linked_print(&ref);

    linked_pop(&ref);
    linked_pop(&ref);
    linked_pop(&ref);
    linked_pop(&ref);
    linked_pop(&ref);
    printf("\nPOP:\n");
    printf("expected: <->1<->\n");
    printf("result  : ");
    linked_print(&ref);
}