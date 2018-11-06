// tests

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked_list_generic.h"
#include "print_lists.h"
#include "list_functions.h"

#define run_test(f_name)\
	printf("%s\n", #f_name);\
	f_name();

void test_init()
{
	Linked_list_generic * list = linked_list_init();
	assert(0 == len(list));
}

void test_add()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	add(list, ptr, data_size);
	assert (*(int *) list->head->data == 10);
	assert (1 == len(list));
}

void test_pop()
{	
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	add(list, ptr, data_size);
	pop(list);
	assert (0 == len(list));
}

void test_first()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	first(list);
	add(list, ptr, data_size);
	assert ( 10 == get_int( first(list)));
	
}

void test_len()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	add(list, ptr, data_size);
	assert (1 == len(list));
}

void test_is_empty()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	assert (is_empty(list));
	add(list, ptr, data_size);
	assert (! is_empty(list));
	
}

void test_print_int()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int arr[] = {10, 20, 30, 40, 50}; 
    for (int i=4; i>=0; i--)
		add(list, arr + i, data_size); 
    assert (*(int *) list->head->data == 10);
    assert (*(int *) list->head->next->data == 20);
    print_list(list, print_int);
}

void test_print_float()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(float);
	float arr[] = {0.1f, 20.0, 20.01, 29.999};
	for (int i = 3;i>=0;i--)
		add(list, arr + i, data_size);
	assert ( (*(float *) list->head->data > 0.1 - 0.00001) && (*(float *) list->head->data < 0.1 + 0.00001));
    assert ( (*(float *) list->head->next->data > 20.0 - 0.00001) && (*(float *) list->head->data < 20.0 + 0.00001));
    print_list(list, print_float);
}

void test_print_char()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(char);
	char arr[] = {'H', 'e', 'l', 'l', 'o'};
	for (int i = 4;i>=0;i--)
		add(list, arr + i, data_size);
	print_list(list, print_char);
}

void test_print_long()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(long);
	long arr[] = {10, 20, 30, 40, 50}; 
    for (int i=4; i>=0; i--)
		add(list, arr + i, data_size); 
    assert( (*(long *) list->head->data == 10)); 
    assert (*(long *) list->head->next->data == 20);
    print_list(list, print_long);
}

void test_get_int()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	add(list, ptr, data_size);
	assert (10 == get_int(first(list)));
}

void test_get_long()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(long);
	long * ptr;
	long a = 10;
	ptr = &a;
	add(list, ptr, data_size);
    
   get_long(list->head->data);
   assert (10 == get_long(first(list)));
}

void test_get_float()
{
	Linked_list_generic * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(float);
	float arr[] = {0.1f, 20.0, 20.01, 29.999};
	for (int i = 3;i>=0;i--)
		add(list, arr + i, data_size);
	get_float(list->head->data);
}

int main()
{
	printf("\n----------------------------\n");
	run_test(test_init);
	run_test(test_add);
	run_test(test_pop);
	run_test(test_first);
	run_test(test_len);
	run_test(test_is_empty);
	run_test(test_print_int);
	run_test(test_print_float);
	run_test(test_print_char);
	run_test(test_print_long);
	run_test(test_get_int);
	run_test(test_get_long);
	run_test(test_get_float);
	printf("----------------------------");
	printf("\nTests did not detect errors!\n\n");
}
