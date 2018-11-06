### Generic Linked List (via void pointers)

Usage(linux): put ```linked_list_generic.h``` and ```print_lists.h``` somewhere in Path or working directory.           
Tests: in a directory linked_list_generic run: ```./tests.sh``` or ```<your shell> tests.sh``` if you shell is not ```/bin/bash```    
Compiles: ```gcc -std=c99```    

API:    

constructor: ``` Linked_list_generic * linked_list_init()```    
add element to list: ```void add(Linked_list_generic * ptr, int elem)```    
pop: ```void pop(Linked_list_generic * ptr)```    
size: ```size_t len(Linked_list_generic * ptr)```    
empty?: ```bool is_empty(Linked_list_generic * ptr)``` - This one works only in ```C99```, but could be easily fixed, 

Under development, may change!

