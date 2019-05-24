#! /bin/bash
mkdir -p bin && gcc-8 -std=c99 linked_list_test.c linked_list.h -o bin/test_list && ./bin/test_list


