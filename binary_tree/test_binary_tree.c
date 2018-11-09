// tests

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_tree.h"
#include "print_tree.h"
#include "node_functions.h"
#include "tree_functions.h"


#define run_test(f_name)\
	printf("%s\n", #f_name);\
	f_name();

void test_init()
{
	Tree * tree = tree_init();
	assert (0 == len(tree));
}

void test_node_init()
{
	int * int_ptr;
	char * char_ptr;
	int a = 10;
	char c = 'A';
	size_t size_key = sizeof(int);
	size_t size_data = sizeof(char);
	int_ptr = &a;
	char_ptr = &c;
	struct node * tree_node = node_init(int_ptr, char_ptr, size_key, size_data);
	assert (tree_node->key);
	assert (tree_node->data);
	assert (! tree_node->parent);
	assert (! tree_node->left);
	assert (! tree_node->right);
}

void test_has_left_child()
{	
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert (! has_left_child(tree_node));
}

void test_has_right_child()
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert ( ! has_right_child(tree_node));
}

void test_is_left_child()
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert (! is_left_child(tree_node));
}

void test_is_right_child()
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert (! is_right_child(tree_node));
}

void test_is_root()
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	tree_node->parent = (struct node *) 1;
	assert (! is_root(tree_node) );
}

void test_is_leaf()
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert ( is_leaf(tree_node));
}

void test_has_any_children()
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert ( ! has_any_children(tree_node));
}

void test_has_both_children()
{
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert ( ! has_both_children(tree_node));
}

void test_replace_node_data()
{
	
	int * int_ptr;
	char * char_ptr;
	int a = 10;
	char c = 'A';
	size_t size_key = sizeof(int);
	size_t size_data = sizeof(char);
	int_ptr = &a;
	char_ptr = &c;
	struct node * tree_node = tree_init();
	struct node * node_left = node_init(int_ptr, char_ptr, size_key, size_data);
	struct node * node_right = node_init(int_ptr, char_ptr, size_key, size_data);
	replace_node_data(tree_node, int_ptr, char_ptr, node_left, node_right);
}

int main()
{	printf("--------------------------------\n\n");
	run_test(test_init);
	run_test(test_node_init);
	run_test(test_has_left_child);
	run_test(test_has_right_child);
	run_test(test_is_left_child);
	run_test(test_is_right_child);
	run_test(test_is_root);
	run_test(test_is_leaf);
	run_test(test_has_any_children);
	run_test(test_has_both_children);
	run_test(test_replace_node_data);
	printf("\n--------------------------------\n");
	return 0;
}
