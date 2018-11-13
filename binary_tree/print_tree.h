/*
 * print_tree.h
 * 
 * Copyleft 2018 lion137
 * 
 * 
 */
#ifndef print_tree_h
#define print_tree_h
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
/*
 * print tree during inorder traversal
*/
void print_inorder(Tree * tree){
	struct node * current = tree->root;
	return __print_inorder(current, tree);
}

// helper to inorder ptrint
void __print_inorder(struct node * current, Tree * tree1){
	if (current){
		__print_inorder(current->left, tree1);
		//prints
		if (STREQ("char", tree1->key_dtype)){
			print_char(current->key);
		}
		if (STREQ("int", tree1->key_dtype)){
			print_int(current->key);
		}
		if (STREQ("float", tree1->key_dtype)){
			print_float(current->key);
		}
		if (STREQ("long", tree1->key_dtype)){
			print_long(current->key);
		}
		if (STREQ("string", tree1->key_dtype)){
			print_string(current->key);
		}
		if (STREQ("char", tree1->val_dtype)){
			print_char(current->data);
		}
		if (STREQ("int", tree1->val_dtype)){
			print_int(current->data);
		}
		if (STREQ("float", tree1->val_dtype)){
			print_float(current->data);
		}
		if (STREQ("long", tree1->val_dtype)){
			print_long(current->data);
		}
		if (STREQ("string", tree1->val_dtype)){
			print_string(current->data);
		}
		printf("\n");
		//end of prints
		__print_inorder(current->right, tree1);
	}
}
  
// Function to print an integer 
void print_int(void *n) { 
   printf(" %d", *(int *)n); 
} 
  
// Function to print a float 
void print_float(void *f) { 
   printf(" %f", *(float *)f); 
} 

//print long
void print_long(void *l){
	printf(" %l", *(long * )l);
}

//print char
void print_char(void * c){
	printf(" %c", * (char * )c);
}

// print string
void print_string(char * str){
	printf(" %s", str);
}

#endif


