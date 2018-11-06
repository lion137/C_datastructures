#! /bin/bash
mkdir -p bin && gcc -std=c99 test_linked_list.c print_lists.h linked_list_generic.h list_functions.h -o bin/test_list && ./bin/test_list
