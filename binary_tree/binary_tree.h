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
#include <string.h>

#define STREQ(a, b) (strcmp((a), (b)) == 0) /*string equality*/

/*
 * Definitions
 */
 
typedef int bool;

size_t max_str_size = 30; // defines maximum string size

/*
 * Struct Tree<T>
 */

typedef struct 
{
	int length;
	char * key_dtype;
	char * val_dtype;
	struct node * root;
} Tree;

/*
 * Struct node 
 */
struct node
{
	void * key;
	void * data;
	struct node * left;
	struct node * right;
	struct node * parent;
};

/*
 * Tree constructor, takes key datatype as a string
 */ 

Tree * tree_init(char * __key_dtype, char * __val_dtype){	
	Tree * tree = (Tree * ) malloc(sizeof(Tree));
	if (tree == NULL) {
		fprintf(stderr, "%s", "Tree, constructor: Malloc failed!\n");
		abort();
	}
	tree->key_dtype = __key_dtype;
	tree->val_dtype = __val_dtype;
	return tree;
}

/*
 * node constructor, returns new node, takes void pointers to key and data, 
 * sizes of key and data and pointers to left child, righjt child and parent
 */
struct node * node_init(void * _key, void * _data, size_t key_size, size_t data_size, 
				struct node *_left, struct node *_right, struct node *_parent)
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	if (tree_node) 
	{	
		tree_node->data  = malloc(data_size);
		for (int i = 0; i<data_size; i++) 
			*(char *)(tree_node->data + i) = *(char *)(_data + i);
		tree_node->key  = malloc(key_size);
		for (int i = 0; i<key_size; i++) 
			*(char *)(tree_node->key + i) = *(char *)(_key + i);
		
		tree_node->left = _left;
		tree_node->right = _right;
		tree_node->parent = _parent;
		return tree_node;
	}
	fprintf(stderr, "%s", "node constructor: Malloc failed!\n");
	abort();
}

int len(Tree * tree) /* length of data structure */
{
	return tree->length;
}

#endif
