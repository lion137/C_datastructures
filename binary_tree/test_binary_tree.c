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

void test_init(){
	Tree * tree = tree_init("int", "char");
	assert (0 == tree->root);
	assert (0 == len(tree));
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

void test_find_data_loader(){
	
	int  * int_p;
	char * charptr;
	size_t size_data = sizeof(char);
	size_t size_key  = sizeof(int);
	int n = 137;
	char c = 'P';
	charptr = &c;
	int_p = &n;
	Tree * tree = tree_init("int", "char");
	struct node * tree_node = node_init(int_p, charptr, size_key, size_data, NULL, NULL, NULL);
	tree->root = tree_node;
	__find_data_loader(tree->key_dtype);
	assert (get_data(tree->root->key) == 137);
	
	
	long * long_p;
	size_t size_key1 = sizeof(long);
	long m = 111137;
	long_p = &m;
	Tree * tree1 = tree_init("long", "char");
	struct node * tree_node1 = node_init(long_p, charptr, size_key1, size_data, NULL, NULL, NULL);
	tree1->root = tree_node1;
	__find_data_loader(tree1->key_dtype);
	assert (get_data(tree1->root->key) == 111137);
	assert (get_data(tree->root->key) == 137);
	
	
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
void test_get_string()
{	
	char  * str_ptr = "Hello";
	float * char_ptr;
	float c = 3.14;
	size_t size_key = sizeof(char) * max_str_size;
	size_t size_data = sizeof(float);
	char_ptr = &c;
	struct node * tree_node = node_init(str_ptr, char_ptr, size_key, size_data, 0, 0, 0);
	__find_data_loader("float");
	assert (STREQ(tree_node->key, "Hello"));
	assert ((*float_ptr)(tree_node->data) == 3.14f);
}

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
	struct node * tree_node = tree_init("float", "char");
	struct node * node_left = node_init(int_ptr, char_ptr, size_key, size_data, 0, 0, 0);
	struct node * node_right = node_init(int_ptr, char_ptr, size_key, size_data, 0, 0, 0);
	replace_node_data(tree_node, int_ptr, char_ptr, node_left, node_right, size_key, size_data);
	assert (10 == get_int(tree_node->key));
	assert ('A' == get_char(tree_node->data));
	assert (tree_node->left == node_left);
	assert (tree_node->right == node_right);
	assert (tree_node->left->parent == tree_node);
	assert (tree_node->right->parent == tree_node);
	
}

int main()
{	printf("--------------------------------\n\n");
	run_test(test_init);
	run_test(test_node_init_nulls);
	run_test(test_node_init_non_nulls);
	run_test(test_find_data_loader);
	run_test(test_put);
	run_test(test_has_left_child);
	run_test(test_has_right_child);
	run_test(test_is_left_child);
	run_test(test_is_right_child);
	run_test(test_is_root);
	run_test(test_is_leaf);
	run_test(test_has_any_children);
	run_test(test_has_both_children);
	run_test(test_get_string);
	run_test(test_replace_node_data);
	printf("\n--------------------------------\n");
	
	return 0;
}
