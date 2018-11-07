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
};

/*
 * constructor
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

int len(Tree * tree)
{
	return tree->length;
}

#endif
