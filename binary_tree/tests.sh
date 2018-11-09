#! /bin/bash
mkdir -p bin && gcc -std=c99 -Wall -pedantic test_binary_tree.c binary_tree.h  print_tree.h node_functions.h tree_functions.h -o bin/test_tree && ./bin/test_tree 
