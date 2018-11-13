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
			size_t val_size){
	if (__compare(tree, _key, tree_node->key) < 0){
		if (has_left_child(tree_node)){
			__put(tree, tree_node->left, _key, _value, key_size, val_size);
		}
		else{
			tree_node->left = node_init(_key, _value, key_size, val_size, NULL, NULL, tree_node);
		}
	}
	else if (__compare(tree, _key, tree_node->key) > 0){
		if (has_right_child(tree_node)){
			__put(tree, tree_node->right, _key, _value, key_size, val_size);
		}
		else{
			tree_node->right = node_init(_key, _value, key_size, val_size, NULL, NULL, tree_node);
		}
	}
	else{
		__replace_node_data(tree_node, _key, _value, tree_node->left, tree_node->right,
							key_size, val_size);
	}
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
 * Function to compare keys, takes a tree and two void pointers
 * returns int 1 - p1 > p2
 * returns -1 - p1 < p2, zero if equal
 */
 
 int __compare(Tree * tree, void * p1, void * p2){
	if (STREQ("int", tree->key_dtype)){
		int left_value = * (int *) p1;
		int right_value = * (int *) p2;
		if (left_value > right_value){ 
			return 1;
		}
		else if (left_value < right_value){
				return -1;
		}
		else{
			return 0;
		}
	}
	if (STREQ("float", tree->key_dtype)){
		float left_value = * (float *) p1;
		float right_value = * (float *) p2;
		if (left_value > right_value){ 
			return 1;
		}
		else if (left_value < right_value){
				return -1;
		}
		else{
			return 0;
		}
	}
	if (STREQ("char", tree->key_dtype)){
		char left_value = * (char *) p1;
		char right_value = * (char *) p2;
		if (left_value > right_value){ 
			return 1;
		}
		else if (left_value < right_value){
				return -1;
		}
		else{
			return 0;
		}
	}
	if (STREQ("long", tree->key_dtype)){
		long left_value = * (long *) p1;
		long right_value = * (long *) p2;
		if (left_value > right_value){ 
			return 1;
		}
		else if (left_value < right_value){
				return -1;
		}
		else{
			return 0;
		}
	}
	if (STREQ("string", tree->key_dtype)){
		if (strcmp(p1, p2) > 0){ 
			return 1;
		}
		else if  (strcmp(p1, p2) < 0){
				return -1;
		}
		else{
			return 0;
		}
	}
	
}


#endif 
