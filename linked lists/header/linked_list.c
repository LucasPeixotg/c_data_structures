#include <malloc.h>

struct node {
    int data;
    int key;
    struct node* next;
};

struct linked_list {
    int size;
    struct node* head;
};

void push(struct linked_list* header, int value, int key) {
    struct node* new = malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    new->key = key;
    
    if(header->size == 0) {
        header->head = new;
        header->size++;
        return;
    }

    struct node* current = header->head;
    while(current->next != NULL) current = current->next;

    current->next = new;
    header->size++;
}

void push_beggining(struct linked_list* header, int value, int key) {
    struct node* new = malloc(sizeof(struct node));
    new->data = value;

    new->next = header->head;
    header->head = new;
    header->size++;
    new->key = key;
}

void pop(struct linked_list* header) {
    if(header->head == NULL) return;
    if(header->head->next == NULL) {
        free(header->head);
        header->head = NULL;
        header->size--;
        return;
    }

    struct node* current = header->head;
    while(current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    header->size--;
}

void pop_beggining(struct linked_list* header) {
    if(header->head != NULL) {
        struct node* next = header->head->next;
        free(header->head);
        header->head = next;
        header->size--;
    }
}

void print_list(struct linked_list* header) {
    struct node* current = header->head;
    while(current != NULL) {
        printf("[%d] %d -> ", current->key, current->data);
        current = current->next;
    }
    printf("\n");
}

int add_offset(struct linked_list* header, int key, int offset) {
    if(header->head == NULL) return 1;

    struct node** previous = &(header->head);
    struct node* current = header->head;

    int i = 0;
    while(current != NULL) {
        if(current->key == key) break;
        if(i >= offset) previous = &((*previous)->next);
        current = current->next;
        i++;
    }

    if(current == NULL) return 1;

    struct node* new = malloc(sizeof(struct node));
    new->data = current->data;
    new->key = key;

    new->next = *previous;
    *previous = new;

    return 0;
}

void remove_odds_between_even(struct linked_list* header) {
    struct node* current = header->head;
    if(current->next == NULL && current->data % 2 == 1) {
        free(current);
        header->head = NULL;
        return;
    }

    int odd_found = 0;
    int event_found = 0;
    while(current != NULL) {
        if(current->next && current->next->data % 2 == 1) {
            if(event_found) {
                struct node* next = current->next->next;
                free(current->next);
                current->next = next;
                odd_found = 1;
                continue;
            }
        } else {
            if(odd_found) break;
            event_found = 1;
        };
        current = current->next;
    }
}