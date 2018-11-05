###C_datastructures   
Single Linked List    
Usage(linux): put ```linked_list.h``` somewhere in Path or working directory.           
Tests: in a directory linked_list run: ```test_runb.sh``` or ```shell test_run.sh``` if you shell is not ```/bin/bash```    
API:    
constructor: ``` Linked_list * linked_list_init()```    
add element to list: ```void add(Linked_list * ptr, int elem)```    
pop: ```void pop()```    
size: ```size_t len(Linked_list * ptr)```    
empty?: ```bool is_empty(Linked_list * ptr)``` - This one works only in ```C99```, but could be easily fixed,

