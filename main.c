#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;

typedef struct listnode {
    Item data;
    struct listnode *next;
} Node;

typedef struct {
    Node *head;
} List;

Node* node_create() {

	Node *node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    return(node);
}

List* list_create()
{
    List *list = (List*) malloc(sizeof(List));
    list->head = NULL;  
    return list;
}
int list_size(List* list)
{
	Node* temp = list->head;
	int size = 0;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}
void list_clear(List *list)
{
	Node *del = list->head;
	while (del != NULL) {
		Node *tmp = del->next;
		free(del);
		del = tmp;
	}
	list->head = NULL;

}


void list_insert(List* list, Node *after_node, Item value)
{
	Node *inserted = (Node*) malloc(sizeof(Node));
    inserted->data = value;
	if (after_node == NULL) {
    	inserted->next = list->head;
    	list->head = inserted;
    } else {	    
	    inserted->next = after_node->next;
	    after_node->next = inserted;
	}
    
}

Node* list_node_find(List* list, Item value)
{

	Node* tmp = list->head;
	while(tmp!= NULL) {
		if (tmp->data == value) {
			return tmp;
		}
		tmp=tmp->next;
	}
	if (value == 0) {
		return NULL;
	} else {
		fprintf(stderr, "Error: value is out of range\n");
		exit(1);
	}	
}

void list_print(List *list)
{
	Node *temp = list->head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void list_task(List*list, Item value)
{
	list_clear(list);
	list_insert(list,0, value);

}

int main(void) {

	List* list= list_create();
	int value=0;
	int pred=0;
	int val=0;	
	char s[7];
   	while (1) {
        scanf("%7s", s);
        if (!strcmp(s, "insert") || !strcmp(s, "ins")) {
			while (scanf("%d %d", &value, &pred)) {
       			Node *after_node = NULL;
		        after_node = list_node_find(list, pred);
		        list_insert(list, after_node, value);
		    }    
		} else if (!strcmp(s, "print") || !strcmp(s, "del")) {
            list_print(list);
        } else if (!strcmp(s, "clear")) {
        	list_clear(list);
        } else if (!strcmp(s, "task")) {
        	scanf("%d", &val);
        	list_task(list, val);
        }
	}


	return 0;
}
