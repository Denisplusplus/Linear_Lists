#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "iterator.h"

int main(void) {

	List* list= list_create();
	char value;
	char pred;
	char del;
	char s[7];
   	while (1) {
        scanf("%7s", s);
        if (!strcmp(s, "add")) {
			scanf(" %c %c", &value, &pred);
       			Node *after_node = NULL;
		        after_node = list_node_find(list, pred);
		        list_insert(list, after_node, value);
		        
		} else if (!strcmp(s, "print")) {
            list_print(list);    
        } else if (!strcmp(s, "lenght")) {
            printf("%d\n",list_lenght(list));
        } else if (!strcmp(s, "clear")) {
        	list_clear(list);
        } else if (!strcmp(s, "task")) {
        	char val;
        	scanf(" %c", &val);
        	Node *new= list_node_find(list, val);
        	list_task(list, val);
        } else if (!strcmp(s, "help")) {
        	help();
        } else if (!strcmp(s, "delete")) {
        	scanf(" %c", &del);
        	if(list_lenght(list) == 0) {
        		printf("Nothing to delete. List is empty\n");
        	} else {
        		Node* dl=list_node_find(list, del);
        		list_delete_node(list, dl);
        	}
        } else if (!strcmp(s, "exit")) {
        	list_destroy(&list);
        	break;   
        } else if (!strcmp(s, "first")) {
  			 iterator_first(list);
        } else if (!strcmp(s, "last")) {
        	iterator_last(list);
        } else if (!strcmp(s, "next")) {
        	scanf(" %c", &value);
        	Node *node= list_node_find(list, value);
        	iterator_next(list, node);
        } else {
        	list_destroy(&list);
            printf("An error occurred. Type 'help' to find the solution\n");
            exit(2);
        
        } 
	}


	return 0;
}
