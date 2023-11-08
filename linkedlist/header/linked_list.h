struct node;

struct linked_list {
    int size;
    struct node* head;
};

void push(struct linked_list* linked_list, int value, int key);
void push_beggining(struct linked_list* header, int value, int key);
void pop(struct linked_list* header);
void pop_beggining(struct linked_list* header);
void print_list(struct linked_list* header);
int add_offset(struct linked_list* header, int key, int offset);
int remove_odds_between_even(struct linked_list* header);