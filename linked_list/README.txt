### C_datastructures   
Single Linked List    
Usage: put ```linked_list.h``` somwhere in Path.        
Tests: in directory linked)list run: ```test_runb.sh``` or ```bash test_run.sh``` if you shell is not ```/bin/bash```    
API:    
constructor: ```linked_list_init()```    
add element to list: ```void add(Linked_list * ptr, int elem)```    
pop: ```void pop()```    
size: ```size_t len(Linked_list * ptr)```    
empty?: ```bool is_empty(Linked_list * ptr)``` - This one works only in ```C99```, but could be easily fixed,

