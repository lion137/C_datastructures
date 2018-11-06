/*
 * linked_list_generic.h
 * 
 * Copyleft 2018 lion <lion@HAL-9002>
 * 
 * 
 */
#ifndef linked_list_generic_h
#define linked_list_generic_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Struct List<T>
typedef struct
{
	size_t length;
	struct inside_node * head; 
	
} Linked_list_generic;

//Struct inside_node (holds list values)
struct inside_node
{
	void * data;
	struct inside_node * next;
};

//List Interface: init, add, pop, nth, len, is_empty

// constructor
Linked_list_generic * linked_list_init()
{
	Linked_list_generic * obj = (Linked_list_generic * ) malloc(sizeof(Linked_list_generic));
	if (obj == NULL) {
		fprintf(stderr, "%s", "Linked_list generic, constructor: Malloc failed!\n");
		abort();
	}
	return obj;
}

//add to the beginning of the list, mutates a list
void add(Linked_list_generic * list, void * _data, size_t data_size) 
{  
    struct inside_node * obj = (struct inside_node *)malloc(sizeof(struct inside_node)); 
	obj->data  = malloc(data_size);
	
	// assume that char takes 1 byte and copy data
    for (int i = 0; i<data_size; i++) 
        *(char *)(obj->data + i) = *(char *)(_data + i);
        
	if ( 0 == list->length){
		list->head = obj;
		list->length++; 
	}
	else {
		obj->next = list->head;
		list->head = obj;
		list->length++; 
	}
} 
// pop the first element, mutates a list
void pop(Linked_list_generic * a_list)
{
	if ( 0 == a_list->length)
		fprintf(stderr, "%s", "Linked list generic, pop: Pop from empty list!\n");
	struct inside_node * tmp = a_list->head;
	a_list->head = a_list->head->next;
	free(tmp);
	tmp = NULL;
	a_list->length--;
}

// returns pointer it's up to client to get desired value, can use functions:
// get_int, get_float, get_long and get_char.
void * first(Linked_list_generic * list)
{
	return list->head->data;
}


Linked_list_generic * rest(Linked_list_generic * list)
{	
	Linked_list_generic * obj = (Linked_list_generic * ) malloc(sizeof(Linked_list_generic));
	if (obj == NULL) {
		fprintf(stderr, "%s", "Linked_list generic, rest: Malloc failed!\n");
		abort();
	}
	obj->head = list->head->next;
	return obj;
	
}

//nth element, returns void pointer, like the function first above, 
// with O(n) time complexity, if -1 returns the last element   
void * nth(Linked_list_generic * list, int n)
{
	struct inside_node * tmp = list->head;
	int limit = 0;
	if (n == -1)
		n = list->length - 1;
	while (n > limit)
	{
		tmp = tmp->next;
		n -= 1;
	}
	return tmp->data;
}

// length of data structure
size_t len(Linked_list_generic * list){
	return list->length;}

bool is_empty(Linked_list_generic * list){
	return len(list) == 0;}

#endif
