/*
 * linked_list.h
 * 
 * Copyleft 2018 lion <lion@HAL-9002>
 * 
 * 
 */
#ifndef linked_list_h
#define linked_list_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//Struct List<int>
typedef struct
{
	size_t length;
	struct inside_node * head; 
	
} Linked_list;

// Struct Node (holds list values)
struct inside_node
{
	int data;
	struct inside_node * next;
};

//List Interface: init, add, pop, len, is_empty

// constructor
Linked_list * linked_list_init()
{
	Linked_list * obj = (Linked_list * ) malloc(sizeof(Linked_list));
	if (obj == NULL) {
		fprintf(stderr, "%s", "linked_list, constructor: Malloc failed!\n");
		abort();
	}
	return obj;
}

// add to linked list
void add(Linked_list * a_list, int elem)
{
	struct inside_node * obj = (struct inside_node *) malloc(sizeof(struct inside_node));
	if (0 == a_list->length)
	{
		obj->data = elem;
		a_list->head = obj;
		a_list->length++;
	}
	else 
	{	
		obj->data = elem;
		obj->next = a_list->head;
		a_list->head = obj;
		a_list->length++;
	}
}

void pop(Linked_list * a_list)
{
	if ( 0 == a_list->length){
		fprintf(stderr, "%s", "linked_list, pop: Pop from empty list!\n");
		return;}
	struct inside_node * tmp = a_list->head;
	a_list->head = a_list->head->next;
	free(tmp);
	a_list->length--;
}

size_t len(Linked_list * a_list)
{
	return a_list->length;
}

bool is_empty(Linked_list * a_list)
{
	return 0 == len(a_list);
}

// printing

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

#endif
