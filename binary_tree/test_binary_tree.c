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

void test_tree_init(){
	Tree * tree = tree_init("int");
	assert (0 == tree->root);
	assert (0 == len(tree));
	assert ("int" == tree->key_dtype);
}

void test_node_init_nulls(){
	int * int_ptr;
	char * char_ptr;
	int a = 10;
	char c = 'A';
	size_t size_key = sizeof(int);
	size_t size_data = sizeof(char);
	int_ptr = &a;
	char_ptr = &c;
	struct node * tree_node = node_init(int_ptr, char_ptr, size_key, size_data, NULL, NULL, NULL);
	assert (tree_node->key);
	assert (tree_node->data);
	assert (! tree_node->parent);
	assert (! tree_node->left);
	assert (! tree_node->right);
}

void test_node_init_non_nulls(){
	int * int_ptr;
	char * char_ptr;
	int a = 10;
	char c = 'A';
	size_t size_key = sizeof(int);
	size_t size_data = sizeof(char);
	int_ptr = &a;
	char_ptr = &c;
	struct node * tree_node3 = node_init(int_ptr, char_ptr, size_key, size_data, NULL, NULL, NULL);
	struct node * tree_node2 = node_init(int_ptr, char_ptr, size_key, size_data, NULL, NULL, NULL);
	struct node * tree_node1 = node_init(int_ptr, char_ptr, size_key, size_data, NULL, NULL, NULL);
	struct node * tree_node = node_init(int_ptr, char_ptr, size_key, size_data, tree_node1, tree_node2, tree_node3);
	assert (tree_node->key);
	assert (tree_node->data);
	assert (tree_node->parent == tree_node3);
	assert (tree_node->left == tree_node1);
	assert (tree_node->right == tree_node2);
}

void test_get_data(){
	Tree * tree = tree_init("int");
	Tree * tree1 = tree_init("char");
	Tree * tree2 = tree_init("float");
	Tree * tree3 = tree_init("long");
	
	int * int_p;
	char * char_ptr;
	int a = 10;
	char c = 'A';
	size_t size_key = sizeof(int);
	size_t size_data = sizeof(char);
	int_p = &a;
	char_ptr = &c;
	struct node * tree_node = node_init(int_p, char_ptr, size_key, size_data, NULL, NULL, NULL);
	
	char * char_p;
	char * char_ptr1;
	char a1 = 'P';
	char c1 = 'A';
	size_t size_key1 = sizeof(char);
	size_t size_data1 = sizeof(char);
	char_p = &a1;
	char_ptr1 = &c1;
	struct node * tree_node1 = node_init(char_p, char_ptr1, size_key1, size_data1, NULL, NULL, NULL);
	
	float * float_p;
	char * char_ptr2;
	float a2 = 3.14f;
	char c2 = 'A';
	size_t size_key2 = sizeof(float);
	size_t size_data2 = sizeof(char);
	float_p = &a2;
	char_ptr2 = &c2;
	struct node * tree_node2 = node_init(float_p, char_ptr2, size_key2, size_data2, NULL, NULL, NULL);
	
	long * long_p;
	char * char_ptr3;
	long a3 = 111000111L;
	char c3 = 'A';
	size_t size_key3 = sizeof(float);
	size_t size_data3 = sizeof(char);
	long_p = &a3;
	char_ptr3 = &c3;
	struct node * tree_node3 = node_init(long_p, char_ptr3, size_key3, size_data3, NULL, NULL, NULL);
	
	tree->root = tree_node;
	assert ( __get_data(tree->root->key) == 10);
	
}

void test_put(){
	;
}

void test_has_left_child(){	
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert (! has_left_child(tree_node));
}

void test_has_right_child(){
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert ( ! has_right_child(tree_node));
}

void test_is_left_child(){
	struct node * tree_node = (struct node *) malloc(sizeof(struct node));
	assert (! is_left_child(tree_node));
}

void test_is_right_child(){
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

/*
 * Get data tests 
 */ 


// struct node tests

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
	struct node * tree_node = node_init(int_ptr, char_ptr, size_key, size_data, NULL, NULL, NULL);
	struct node * node_left = node_init(int_ptr, char_ptr, size_key, size_data, 0, 0, 0);
	struct node * node_right = node_init(int_ptr, char_ptr, size_key, size_data, 0, 0, 0);
	__replace_node_data(tree_node, int_ptr, char_ptr, node_left, node_right, size_key, size_data);
	assert (10 == __get_int(tree_node->key));
	assert ('A' == __get_char(tree_node->data));
	assert (tree_node->left == node_left);
	assert (tree_node->right == node_right);
	assert (tree_node->left->parent == tree_node);
	assert (tree_node->right->parent == tree_node);
	
}

int main()
{	printf("--------------------------------\n\n");
	run_test(test_tree_init);
	run_test(test_node_init_nulls);
	run_test(test_node_init_non_nulls);
	run_test(test_get_data);
	run_test(test_put);
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
