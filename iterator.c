#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "list.h"


void iterator_first(List* list)
{
	printf("%c\n", list->head->data);
}


void iterator_last(List* list) 
{
	Node* tmp = list->head;
	while(tmp->next) {
		tmp=tmp->next;
	}

	printf("%c\n", tmp->data);

}

void iterator_next(List* list, Node* node)
{
	if (node==NULL)  {
		list_destroy(&list);
		fprintf(stderr, "Error: value is out of range\n");
		exit(1);
	} else if (node->next==NULL) {
		printf("This is the last element\n");
	} else {
		printf("%c\n", node->next->data);
	}
}
