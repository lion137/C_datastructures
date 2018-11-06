// functions to print lists

/*
 * 
 Copyleft 2018 lion137 
 * 
 * 
 */

#ifndef print_lists_h
#define print_list_h 	
#include <stdio.h>
#include <stdlib.h>
#include "linked_list_generic.h"

void print_list(Linked_list_generic * list, void (* f_ptr) (void *))
{
	printf("[");
	struct inside_node * tmp = list->head;
	while (tmp != NULL) 
    { 
        (*f_ptr)(tmp->data); 
        tmp = tmp->next; 
    } 
    printf("]\n");
}
// functions to print certain datatypes

void print_int(void *n) 
{ 
   printf("%d, ", *(int *) n); 
}

void print_long(void *n) 
{ 
   printf("%li, ", *(long *) n); 
} 

void print_float(void * f)
{
	printf("%f, ", * (float *) f);
}

void print_char(void * c)
{
	printf("%c", * (char *) c);
}

#endif

