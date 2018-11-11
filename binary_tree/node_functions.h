/*
 * node_functions.h
 * copyleft 2018 lion137
 * 
 */
 
#ifndef node_functions_h
#define node_functions_h
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

bool has_left_child(struct node * tree_node)
{	
	return ( tree_node->left != NULL );
}

bool has_right_child(struct node * tree_node)
{
	return ( tree_node->right != NULL);
}

bool is_left_child(struct node * tree_node)
{
	return ( (tree_node->parent) && (tree_node->parent->left == tree_node) );
}

bool is_right_child(struct node * tree_node)
{
	return ( (tree_node->parent) && (tree_node->parent->right == tree_node) );
}

bool is_root(struct node * tree_node)
{
	return ( (tree_node->parent == tree_node));
}

bool is_leaf(struct node * tree_node)
{
	return ( ! ( (tree_node->right) || (tree_node->left)) );
}

bool has_any_children(struct node * tree_node)
{
	return (tree_node->right || tree_node->left);
}

bool has_both_children(struct node * tree_node)
{
	return ( tree_node->right && tree_node->left); 
}

void __replace_node_data(struct node * tree_node, void * _key, void * _value, struct node * _tleft, 
					   struct node * _tright, size_t key_size, size_t val_size)
{
	tree_node->data = malloc(val_size);
	tree_node->key = malloc(key_size);
	for (int i = 0; i<key_size; i++) 
        *(char *)(tree_node->key + i) = *(char *)(_key + i);
    for (int i = 0; i<val_size; i++) 
        *(char *)(tree_node->data + i) = *(char *)(_value + i);
    tree_node->left = _tleft;
    tree_node->right = _tright;
    if (has_left_child(tree_node))
		tree_node->left->parent = tree_node;
	if (has_right_child(tree_node))
		tree_node->right->parent = tree_node;
}


#endif 
