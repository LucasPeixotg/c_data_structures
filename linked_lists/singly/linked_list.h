struct node;

/*
Insert in the beggining of the list
*/
void linked_add(struct node** head_ref, int value);

/*
Insert in the end of the list
*/
void linked_append(struct node** head_ref, int value);

/*
Insert at an specific index, 
or in the end, if the list is smaller than necessary
*/
void linked_insert(struct node** head_ref, int index, int value);

/*
Remove the last node of the list
*/
void linked_pop(struct node** head_ref);

/*
Prints all elements of the list
*/
void linked_print(struct node** head_ref);


struct node* copy_list(struct node** head_ref);

int* to_array(struct node** head_ref);


void destroy(struct node* head);