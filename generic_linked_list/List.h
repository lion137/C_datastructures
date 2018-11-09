/*
 * List.h
 * 
 * Copyleft 2018 lion137
 * 
 * 
 */
#ifndef List_h
#define List_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Struct List<T>
typedef struct
{
	int length;
	struct inside_node * head; 
	
} List;

//Struct inside_node (holds list values)
struct inside_node
{
	void * data;
	struct inside_node * next;
};

//List Interface: init, add, pop, nth, len, is_empty

// constructor
List * linked_list_init()
{
	List * obj = (List * ) malloc(sizeof(List));
	if (obj == NULL) {
		fprintf(stderr, "%s", "Linked_list generic, constructor: Malloc failed!\n");
		abort();
	}
	return obj;
}

//add to the beginning of the list, mutates a list
void add(List * list, void * _data, size_t data_size) 
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

// push element at the beginning of the list, returns a new list
List * cons(void * _data, size_t data_size, List * list)
{
	List * node = (List * ) malloc(sizeof(List));
	if (node == NULL) {
		fprintf(stderr, "%s", "Linked_list generic, constructor: Malloc failed!\n");
		abort();
	}
	
    struct inside_node * obj = (struct inside_node *)malloc(sizeof(struct inside_node)); 
	obj->data  = malloc(data_size);
	
    for (int i = 0; i<data_size; i++) 
        *(char *)(obj->data + i) = *(char *)(_data + i);
    if ( 0 == list->length)
    {
		node->head = obj;
		node->length = list->length + 1;
		return  node;
	}
	else 
	{
		node->head = obj;
		node->length = list->length + 1;
		node->head->next = list->head;
		return node;
	}
}

// pop the first element, mutates a list, 
// returns void pointer to data
void * pop(List * a_list)
{
	if ( 0 == a_list->length)
		fprintf(stderr, "%s", "Linked list generic, pop: pop from empty list!\n");
	struct inside_node * tmp = a_list->head;
	a_list->head = a_list->head->next;
	a_list->length--;
	return tmp->data;
}
// insert elem after given index n, when supplied wit -1
// append at the end of a list
void insert(List * list, void * _data, size_t data_size, int n)
{
	struct inside_node * tmp = list->head;
	struct inside_node * obj = (struct inside_node *)malloc(sizeof(struct inside_node)); 
	obj->data  = malloc(data_size);
	
    for (int i = 0; i<data_size; i++) 
        *(char *)(obj->data + i) = *(char *)(_data + i);
    
    if (n == -1)
		n = list->length - 1;
    if ( 0 == list->length)
    {
		list->head = obj;
		list->length++; 
	}
    else
    {
		while ( n > 0)
		{
			tmp = tmp->next;
			n -= 1;
		}
		struct inside_node * ptr = tmp->next;
		tmp->next = obj;
		tmp->next->next = ptr;
		list->length++;
	}
}

// returns pointer it's up to client to get desired value, can use functions:
// get_int, get_float, get_long and get_char.
void * first(List * list)
{
	return list->head->data;
}


List * rest(List * list)
{	
	List * obj = (List * ) malloc(sizeof(List));
	if (obj == NULL) {
		fprintf(stderr, "%s", "Linked_list generic, rest: Malloc failed!\n");
		abort();
	}
	obj->head = list->head->next;
	return obj;
	
}

//nth element, returns void pointer, like the function first above, 
// with O(n) time complexity, if -1 returns the last element   
void * nth(List * list, int n)
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
int len(List * list){
	return list->length;}

bool is_empty(List * list){
	return len(list) == 0;}

void delete_list(List * ptr)
{free (ptr); ptr = NULL;}

#endif
