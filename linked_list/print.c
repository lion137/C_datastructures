#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_list(Linked_list * a_list)
{	
	char  * l_b = "[";
	char * r_b = "]";
	printf("%s", l_b);
	struct inside_node * tmp = a_list->head;
	
	while (!(tmp == NULL)){
		if (tmp->next == NULL){
			printf("%d", tmp->data);
			tmp = tmp->next;
			break;
		}
		
		printf("%d, ",tmp->data);
		tmp = tmp->next;
	}
	printf("%s", r_b);
}
