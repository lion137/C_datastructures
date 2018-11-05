#! /bin/bash
mkdir -p bin && gcc -std=c99 linked_list_test.c linked_list.h -o bin/test_list && ./bin/test_list


