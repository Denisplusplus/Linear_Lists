#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "list.h"
//#include "iterator.h"

typedef char Item;

List* list_create()
{
    List *list = (List*) malloc(sizeof(List));
    list->head = NULL;  
    return list;
}

void help()
{
    printf("The main function of this app is working with the unidirectional list. \n");
    printf("Use this keys to work with the program: \n");
    printf("- 'add'     - to insert the value to the list\n");
     
    printf("Input the elements in this order:\n");
    printf("1. The value to set up\n"); 
    printf("2. The value after which you have to insert\n");
    printf("Note: if the value after which you want to insert doesn't exist, program should stop working\n"); 
    printf("For inserting the element to the list origin input in this way: 'value' '.'\n"); 
    printf("- 'delete'  - to remove the value from the list\n");
    printf("- 'lenght'  - to gain the list size\n");
    printf("- 'task'    - to start removing the elements that precede and follow the specified value \n");
    printf("- 'print'   - to print the list\n");
    printf("- 'clear'   - to make the list empty \n");
    printf("- 'destroy' - to destroy the list \n");
    printf("- 'exit'    - to quit the application\n");
}

int list_lenght(List* list)
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

Node* iterator_first(List* list)
{
	return(list->head);
}


void list_delete_node(List* list, Node* delete)
{
	
	
	if (delete == list->head) {
		Node*temp= list->head;
		list->head=list->head->next;
		free(temp);
	} else {
		Node* tmp= list->head;
		while (tmp->next != delete) {
			tmp=tmp->next;
		}
		tmp->next= delete->next;
		free(delete);
	}

}

void list_destroy(List **list)
{
	Node *del = (*list)->head;
	while (del != NULL) {
		Node *tmp = del->next;
		free(del);
		del = tmp;
	}
	free (*list);
	*list = NULL;
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
	if (value == '.') {
		return NULL;
	} else {
		list_destroy(&list);
		fprintf(stderr, "Error: value is out of range\n");
		exit(1);
	}	
}

void list_print(List *list)
{
	Node *temp = list->head;
	while (temp != NULL) {
		printf("%c ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void list_task(List* list, Item value)
{
	list_clear(list);
	list_insert(list,'.', value);

}
