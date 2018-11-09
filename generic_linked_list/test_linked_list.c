// tests

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
#include "print_lists.h"
#include "list_functions.h"

#define run_test(f_name)\
	printf("%s\n", #f_name);\
	f_name();

void test_init()
{
	List * list = linked_list_init();
	assert(0 == len(list));
}

void test_add()
{
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	add(list, ptr, data_size);
	assert (*(int *) list->head->data == 10);
	assert (1 == len(list));
}

void test_cons()
{
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int * ptr2;
	int a = 10, b = 20;
	ptr = &a;
	ptr2 = &b;
	add(list, ptr, data_size);
	assert (20 == get_int(first(cons(ptr2, data_size, list))));
}

void test_pop()
{	
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	add(list, ptr, data_size);
	assert (1 == len(list));
	assert (10 == get_int(pop(list)));
	assert (0 == len(list));
}

void test_insert()
{
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(char);
	char arr[] = {'H', 'e', 'l', 'l', 'o'}; 
    for (int i=4; i>=0; i--)
		add(list, arr + i, data_size);
	char * p_char;
	char a = 'Q';
	p_char = &a; 
	insert(list, p_char, data_size, -1);
	assert ( len(list) == 6);
	insert(list, p_char, data_size, 0);
	assert ( get_char(nth(list, 1)) == 'Q');
	assert ( 7 == len(list));
	 
}


void test_first()
{
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int a = 10;
	ptr = &a;
	add(list, ptr, data_size);
	assert ( 10 == get_int( first(list)));
	
}

void test_rest()
{	
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int * ptr1;
	int * ptr2;
	int a = 10, b = 20, c = 30;
	ptr = &a;
	ptr1 = &b;
	ptr2 = &c;
	add(list, ptr, data_size);
	add(list, ptr1, data_size);
	add(list, ptr2, data_size);
	assert (list->head->next->data  ==  rest(list)->head->data);
	assert (get_int(list->head->data)  ==  get_int(first(list)));
}

void test_nth()
{
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int * ptr1;
	int * ptr2;
	int a = 10, b = 20, c = 30;
	ptr = &a;
	ptr1 = &b;
	ptr2 = &c;
	add(list, ptr, data_size);
	add(list, ptr1, data_size);
	add(list, ptr2, data_size);
    assert (get_int(nth(list, 1)) == 20);
    assert (get_int(nth(list, -1)) == 10);
}

void test_reverse()
{
	List * list = linked_list_init();
	List * empty = linked_list_init();
	size_t data_size;
	data_size = sizeof(int);
	int * ptr;
	int * ptr1;
	int * ptr2;
	int a = 10, b = 20, c = 30;
	ptr = &a;
	ptr1 = &b;
	ptr2 = &c;
	add(list, ptr, data_size);
	add(list, ptr1, data_size);
	add(list, ptr2, data_size);
	List * somth = list;
	List * reversed = reverse(list, data_size);
	assert (get_int(nth(reversed, 2)) == get_int(first(list)));
	assert (3 == len(reversed));
	assert (0 == len(reverse(empty, data_size)));
}

void test_len()
{
	List * list = linked_list_init();
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
	List * list = linked_list_init();
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
	List * list = linked_list_init();
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
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(float);
	float arr[] = {0.1f, 20.0, 20.01, 29.999};
	for (int i = 3;i>=0;i--)
		add(list, arr + i, data_size);
	assert ( * (float * ) list->head->data  == 0.1f);
    assert ( (*(float *) list->head->next->data == 20.0f));
    print_list(list, print_float);
}

void test_print_char()
{
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(char);
	char arr[] = {'H', 'e', 'l', 'l', 'o'};
	for (int i = 4;i>=0;i--)
		add(list, arr + i, data_size);
	print_list(list, print_char);
}

void test_print_long()
{
	List * list = linked_list_init();
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
	List * list = linked_list_init();
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
	List * list = linked_list_init();
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
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(float);
	float * ptr;
	float a = 10;
	ptr = &a;
	add(list, ptr, data_size);
	assert ( 10.00000f == get_float(first(list)));
}

void test_get_char()
{
	List * list = linked_list_init();
	size_t data_size;
	data_size = sizeof(char);
	char * ptr;
	char a = 'H';
	ptr = &a;
	add(list, ptr, data_size);
	assert ('H' == get_char(list->head->data));
	assert ('H' == get_char(first(list)));
}

void test_delete_list()
{
	List * ptr;
	ptr = linked_list_init();
	assert (ptr);
	printf("%u\n", sizeof(ptr));
	free (ptr);
	ptr = NULL;
	delete_list(ptr);
	assert (!ptr);
	printf("%u\n", sizeof(ptr));
}

int main()
{
	printf("\n----------------------------\n");
	run_test(test_init);
	run_test(test_add);
	run_test(test_cons);
	run_test(test_pop);
	run_test(test_insert);
	run_test(test_first);
	run_test(test_rest);
	run_test(test_nth);
	run_test(test_reverse);
	run_test(test_len);
	run_test(test_is_empty);
	run_test(test_print_int);
	run_test(test_print_float);
	run_test(test_print_char);
	run_test(test_print_long);
	run_test(test_get_int);
	run_test(test_get_long);
	run_test(test_get_float);
	run_test(test_get_char);
	run_test(test_delete_list);
	printf("----------------------------");
	printf("\nTests did not detect errors!\n\n");
}
