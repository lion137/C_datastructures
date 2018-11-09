/*
 * node_functions.h
 * copyleft 2018 lion137
 * 
 */
 
#ifndef node_functions_h
#define node_functions_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"

bool has_left_child(struct node * tree_node)
{
	return ( tree_node->left );
}

bool has_right_child(struct node * tree_node)
{
	return ( tree_node->right );
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

void replace_node_data(struct node * tree_node, void * _key, void * _value, struct node * _tleft, 
					   struct node * _tright)
{
	;
}

#endif 
