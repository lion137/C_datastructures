// tests

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_tree.h"
#include "print_tree.h"


#define run_test(f_name)\
	printf("%s\n", #f_name);\
	f_name();

void test_init()
{
	Tree * tree = tree_init();
	assert (0 == len(tree));
}

int main()
{	run_test(test_init);
	return 0;
}
