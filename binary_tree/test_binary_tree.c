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
	Tree * tree = tree_init("int", "char");
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
	
	Tree * tree3 = tree_init("long", "char");
	Tree * tree = tree_init("int", "char");
	Tree * tree2 = tree_init("float", "char");
	
	int * int_p; char * char_ptr; int a = 10; char c = 'A';
	size_t size_key = sizeof(int);
	size_t size_data = sizeof(char);
	int_p = &a; char_ptr = &c;
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
	float a2 = 3.0f;
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
	size_t size_key3 = sizeof(long);
	size_t size_data3 = sizeof(char);
	long_p = &a3;
	char_ptr3 = &c3;
	struct node * tree_node3 = node_init(long_p, char_ptr3, size_key3, size_data3, NULL, NULL, NULL);
	
	
	tree3->root = tree_node3;
	assert (__get_long(tree3->root->key) == 111000111L);
	//printf("%d\n", __get_long(tree3->root->key));
	
	tree2->root = tree_node2;
	assert (__get_float(tree2->root->key) == 3.0f);
	//printf("%f\n", __get_float(tree2->root->key));
	
	
}

void test_compare(){
	
	Tree * tree2 = tree_init("float", "char"); // float
	float * float_p;
	char * char_ptr2;
	float a2 = 3.0f;
	char c2 = 'A';
	size_t size_key2 = sizeof(float);
	size_t size_data2 = sizeof(char);
	float_p = &a2;
	char_ptr2 = &c2;
	struct node * tree_node2 = node_init(float_p, char_ptr2, size_key2, size_data2, NULL, NULL, NULL);
	
	tree2->root = tree_node2;
	float * tmp__; float * tmp1__;
	float tmp_val_f = 10.9f, tmp1_val_f = 10.91f;
	tmp__ = &tmp_val_f; tmp1__ = &tmp1_val_f;
	assert (__compare(tree2, tmp__, tmp1__) < 0);
	
	Tree * tree = tree_init("int", "char"); // int
	int * int_p; char * char_ptr; int a = 10; char c = 'A';
	size_t size_key = sizeof(int);
	size_t size_data = sizeof(char);
	int_p = &a; char_ptr = &c;
	struct node * tree_node = node_init(int_p, char_ptr, size_key, size_data, NULL, NULL, NULL);
	
 	tree->root = tree_node;
	int * tmp; int * tmp1;
	int tmp_val = -1, tmp1_val = 1;
	tmp = &tmp_val; tmp1 = &tmp1_val;
	assert (! __compare(tree, tree->root->key, tree->root->key));
	assert ( __compare(tree, tmp, tmp1) < 0);
	
	Tree * tree1 = tree_init("char", "char"); // char
	char * char_p;
	char * char_ptr1;
	char a1 = 'P';
	char c1 = 'A';
	size_t size_key1 = sizeof(char);
	size_t size_data1 = sizeof(char);
	char_p = &a1;
	char_ptr1 = &c1;
	struct node * tree_node1 = node_init(char_p, char_ptr1, size_key1, size_data1, NULL, NULL, NULL);
	tree1->root = tree_node1;
	assert (__compare(tree1, char_p, char_ptr1) > 0);
	assert (__compare(tree1, char_ptr1, char_p) < 0);
	assert (__compare(tree1, tree1->root->key, tree1->root->key) == 0);
	
	Tree * tree3 = tree_init("long", "char"); // long
	long * long_p;
	long * long_p1;
	char * char_ptr3;
	long a3 = 111000111L;
	long a4 = 111L;
	char c3 = 'A';
	size_t size_key3 = sizeof(long);
	size_t size_data3 = sizeof(char);
	long_p = &a3;
	long_p1 = &a4;
	char_ptr3 = &c3;
	struct node * tree_node3 = node_init(long_p, char_ptr3, size_key3, size_data3, NULL, NULL, NULL);
	
	tree3->root = tree_node3;
	assert (__compare(tree3, tree3->root->key, long_p1) > 0);
	assert (__compare(tree3, tree3->root->key, tree3->root->key) == 0);
	assert (__compare(tree3, long_p1, tree3->root->key) < 0);
	
	Tree * tree4 = tree_init("string", "string"); // string
	char  **str1 = "Polska";
	char  **str2 = "Anglia";
	size_t size_key4 = sizeof(char) * max_str_size;
	size_t size_data4 = sizeof(char) * max_str_size;
	struct node * tree_node4 = node_init(str1, str2, size_key4, size_data4, NULL, NULL, NULL);
	tree4->root = tree_node4;
	assert (__compare(tree4, str1, str2) > 0);
	assert (__compare(tree4, str2, str1) < 0);
	assert (__compare(tree4, str1, str1) == 0);
	assert (__compare(tree4, tree4->root->key, tree4->root->data) > 0);
}

void test_put(){
	Tree * tree = tree_init("char", "char");
	char * char_p;
	char * char_ptr1;
	char a1 = 'P';
	char c1 = 'A';
	size_t size_key1 = sizeof(char);
	size_t size_data1 = sizeof(char);
	char_p = &a1;
	char_ptr1 = &c1;
	
	char a2 = 'Z', c2 = 'Q', a3 = 'U', c3 = 'M';
	char * char_p1 = &a2;
	char * char_p2 = &c2; 
	char * char_p3 = &a3; 
	char * char_p4 = &c3; 
	struct node * tree_node1 = node_init(char_p, char_ptr1, size_key1, size_data1, NULL, NULL, NULL);
	put(tree, char_p, char_ptr1, size_key1, size_data1);
	put(tree, char_p1, char_p2, size_key1, size_data1);
	put(tree, char_p3, char_p4, size_key1, size_data1);
	assert(len(tree) == 3);
	assert (__get_char(tree->root->key) == 'P');
	assert (__get_char(tree->root->data) == 'A');
	assert (__get_char(tree->root->right->key) == 'Z');
	assert (__get_char(tree->root->right->data) == 'Q');
	assert (__get_char(tree->root->right->left->key) == 'U');
	assert (__get_char(tree->root->right->left->data) == 'M');
}

void test_get(){
	Tree * tree = tree_init("int", "string");
	int a = 3, b = 2, c = 6, d = 7, e = 9;
	int *int_p, *int_p1, *int_p2, *int_p3;
	int_p = &a;
	int_p1 = &b;
	int_p2 = &c;
	int_p3 = &d;
	char * str1 = "Poland";
	char * str2 = "Russia";
	char * str3 = "Norway";
	char * str4 = "Finland";
	size_t key_size = sizeof(int);
	size_t data_size = sizeof(char) * max_str_size;
	put(tree, int_p, str1, key_size, data_size);
	put(tree, int_p1, str2, key_size, data_size);
	put(tree, int_p2, str3, key_size, data_size);
	put(tree, int_p3, str4, key_size, data_size);
	assert (__compare (tree, get(tree, int_p), str1) == 0);
	assert (__compare (tree, get(tree, int_p1), str2) == 0);
	assert (__compare (tree, get(tree, int_p2), str3) == 0);
	assert (__compare (tree, get(tree, int_p3), str4) == 0);
	assert (!get(tree, &e));
}

void test_contains(){
	Tree * tree = tree_init("int", "string");
	int a = 3, b = 2, c = 6, d = 7, e = 9;
	int *int_p, *int_p1, *int_p2, *int_p3;
	int_p = &a;
	int_p1 = &b;
	int_p2 = &c;
	int_p3 = &d;
	char * str1 = "Poland";
	char * str2 = "Russia";
	char * str3 = "Norway";
	char * str4 = "Finland";
	size_t key_size = sizeof(int);
	size_t data_size = sizeof(char) * max_str_size;
	put(tree, int_p, str1, key_size, data_size);
	put(tree, int_p1, str2, key_size, data_size);
	put(tree, int_p2, str3, key_size, data_size);
	put(tree, int_p3, str4, key_size, data_size);
	assert (! contains(tree, &e));
	assert (contains(tree, int_p));
	assert (contains(tree, int_p1));
}

void test_print_inorder(){
	Tree * tree = tree_init("int", "char");
	char * int_p;
	char * char_p1;
	char * int_p1;
	char * char_ptr2;
	int a1 = 1;
	char a2 = 'A';
	int c1 = 2;
	char c2 = 'B';
	size_t size_key1 = sizeof(int);
	size_t size_data1 = sizeof(char);
	int_p = &a1;
	int_p1 = &c1;
	char_p1 = &a2;
	char_ptr2 = &c2;
	int minus = -1;
	int * int_p2 = &minus;
	int sth = 10;
	int * int_p3 = &sth;
	put(tree, int_p, char_p1, size_key1, size_data1);
	put(tree, int_p1, char_ptr2, size_key1, size_data1);
	put(tree, int_p2, char_ptr2, size_key1, size_data1);
	put(tree, int_p3, char_ptr2, size_key1, size_data1);
	print_inorder(tree);
	printf("\n");
}

/*
 * 
 * Struct node tests
 *
 */ 

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
	run_test(test_compare);
	run_test(test_put);
	run_test(test_get);
	run_test(test_contains);
	run_test(test_print_inorder);
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
