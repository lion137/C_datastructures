// functions operates on lists

/*
 * 
 Copyleft 2018 lion137 
 * 
 * 
 */

#ifndef list_functions_h
#define list_functions_h
#include <stdio.h>
#include <stdlib.h>
#include "linked_list_generic.h"

// cast a void pointer (returned from list) to designated data type
int get_int(void * ptr)
{
	return * (int *) ptr;
}

long get_long(void * ptr)
{
	return * (long *) ptr;
}

float get_float(void * ptr)
{
	return * (float *) ptr;
}

char get_char(void * ptr)
{
	return * (char *) ptr;
}

//internal, implementation detail
Linked_list_generic * _rev(Linked_list_generic * lst1, Linked_list_generic * lst2, size_t data_size)
{
	Linked_list_generic * a_list1 = lst1;
	size_t n = lst1->length;
	while (n > 0)
	{
		lst2 = cons(first(a_list1), data_size, lst2);
		a_list1 = rest(a_list1);
		n--;
	}
	return lst2;
}

//reverse a list
Linked_list_generic * reverse(Linked_list_generic * list, size_t data_size)
{
	Linked_list_generic * empty = linked_list_init();
	return _rev(list, empty, data_size);
}
#endif
