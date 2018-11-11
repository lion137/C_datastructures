/*
 * tree_functions.h
 * copyleft 2018 lion137
 * 
 */
 
#ifndef tree_functions_h
#define tree_functions_h
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


void put(Tree * tree, void * _key, void * _val, size_t key_size, size_t val_size)
{
	if (tree->root)
		__put(tree, tree->root, _key, _val, key_size, val_size);
	else
		tree->root = node_init(_key, _val, key_size, val_size, NULL, NULL, NULL);
	tree->length++;
}

void __put(Tree * tree, struct node * tree_node, void * _key, void *_value, size_t key_size, 
			size_t val_size)
{
	;
}

/*
 * following 5 cast a void pointer to designated data type
 */
 
int __get_int(void * ptr)
{
	return * (int *) ptr;
}

long __get_long(void * ptr)
{
	return * (long *) ptr;
}

float __get_float(void * ptr)
{
	return * (float *) ptr;
}

char __get_char(void * ptr)
{
	return * (char *) ptr;
}

/*
 * Find a function to unpack data
 * param: void pointer
 * void: modifies globals
 */

void __find_data_loader(char * key, char * val){
	
}

#endif 
