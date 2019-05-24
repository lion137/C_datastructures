// tests file

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"


#define run_test(f_name)\
	printf("%s\n", #f_name);\
	f_name();
	

void test_init()
{
	Linked_list * list = linked_list_init();
	assert(0 == list->length);
}

void test_add()
{	
	Linked_list * list = linked_list_init();
	add(list, 42);
	add(list, 1);
	assert (1 == list->head->data);
}

void test_len()
{
	Linked_list * list = linked_list_init();
	add(list, 42);
	assert (1 == len(list));
}

void test_pop()
{
	Linked_list * list = linked_list_init();
	add(list, 42);
	add(list, 1);
	pop(list);
	assert (42 == list->head->data);
	assert (1 == len(list));
}

void test_is_empty()
{
	Linked_list * list = linked_list_init();
	assert (is_empty(list));
	add(list, 42);
	assert (! is_empty(list));
}

void test_print()
{
	Linked_list * list = linked_list_init();
	add(list, 42);
	add(list, 1);
	assert (list->head->data == 1);
	assert (list->head->next->data == 42);
	printf("[%d, ", list->head->data);
	printf("%d] = ", list->head->next->data);
	print_list(list);
	printf("\n");
}

void test_delete() {
	Linked_list * list = linked_list_init();
	add(list, 1);
	add(list, 42);
	add(list, 1);
	add(list, 1);
	print_list(list);
	remove_all(list, 1);
	assert (1 ==len(list));
	assert (list->head->data == 42);
}

int main()
{
	run_test(test_init);
	run_test(test_add);
	run_test(test_len);
	run_test(test_pop);
	run_test(test_is_empty);
	run_test(test_print);
	run_test(test_delete);
	printf("Test Passed\n");
	return 0;
}

