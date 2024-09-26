#include <stdio.h>
#include "linked_list.h"

int main(void) {
    struct node* ref;
    ref = NULL;

    insert_beggining(&ref, 3);
    insert_beggining(&ref, 2);
    insert_beggining(&ref, 1);
    printf("PUSH:\n");
    printf("expected: <->1<->2<->3<->\n");
    printf("result  : ");
    printList(&ref);

    append(&ref, 4);
    append(&ref, 5);
    append(&ref, 6);
    printf("PUSH:\n");
    printf("expected: <->1<->2<->3<->4<->5<->6<->\n");
    printf("result  : ");
    printList(&ref);

    pop(&ref);
    pop(&ref);
    pop(&ref);
    pop(&ref);
    pop(&ref);
    printf("\nPOP:\n");
    printf("expected: <->1<->\n");
    printf("result  : ");
    printList(&ref);
}