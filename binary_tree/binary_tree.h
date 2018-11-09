/*
 * binary_tree.h
 * 
 * Copyleft 2018 lion137
 * 
 * 
 */
#ifndef binary_tree_h
#define binary_tree_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Struct Tree<T>
 */

typedef struct 
{
	int length;
	struct node * head;
} Tree;

struct node
{
	void * key;
	void * data;
	struct node * left;
	struct node * right;
	struct node * parent;
};

/*
 * Tree constructor
 */ 

Tree * tree_init()
{
	Tree * tree = (Tree * ) malloc(sizeof(Tree));
	if (tree == NULL) {
		fprintf(stderr, "%s", "Tree, constructor: Malloc failed!\n");
		abort();
	}
	return tree;
}

/*
 * node constructor
 */
struct node * node_init(void * _key, void * _data, size_t key_size, size_t data_size)
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	if (tree_node) 
	{	
		tree_node->data  = malloc(data_size);
		for (int i = 0; i<data_size; i++) 
			*(char *)(tree_node->data + i) = *(char *)(_data + i);
		tree_node->key  = malloc(key_size);
		for (int i = 0; i<data_size; i++) 
			*(char *)(tree_node->key + i) = *(char *)(_key + i);
		return tree_node;
	}
	fprintf(stderr, "%s", "node constructor: Malloc failed!\n");
	abort();
}

int len(Tree * tree)
{
	return tree->length;
}

#endif
