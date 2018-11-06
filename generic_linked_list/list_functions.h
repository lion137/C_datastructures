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
// here int
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
#endif
