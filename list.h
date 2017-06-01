#ifndef _LIST_H_
#define _LIST_H_

typedef char Item;

typedef struct listnode {
    Item data;
    struct listnode *next;
} Node;

typedef struct {
    Node *head;
} List;


List* list_create();
void help();
int list_lenght(List* list);
void list_clear(List *list);
void list_delete_node(List* list, Node* delete);
void list_destroy(List **list);
void list_insert(List* list, Node *after_node, Item value);
Node* list_node_find(List* list, Item value);
void list_print(List *list);
void list_task(List*list, Item value);



#endif
