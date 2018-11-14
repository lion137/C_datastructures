### Generic Linked List (via void pointers)

Usage(linux): put ```print_lists.h, List.h and  list_functions.h``` somewhere in Path or working directory.           
Tests: in a directory List run: ```./tests.sh``` or ```<your shell> tests.sh``` if you shell is not ```/bin/bash```    
Compiles: ```gcc -std=c99```    

API:    

If not explicitly stated: mutates and/or complexity, assuming doesn't ' mutate original object and  complexity = O(1).

constructor: ``` List * linked_list_init()```    
add element to list: ```void add(List * ptr, int elem)``` mutates           

pop: ```void pop(List * ptr)```    mutates        

size: ```size_t len(List * ptr)```         

empty?: ```bool is_empty(List * ptr)``` - This one works only in ```C99```, but could be easily fixed,.     

Cons: ```cons(void * data, size_t data_size, List * ptr)``` and returns new list with data element prependded
to list.	
    
Insert: ```insert(List * list, void * data, size_t data_size, int n)``` - mutates a list, returns element    
```data``` insertred after ```n```-th element of the list, append at the end when supplied with ```n = -1```. Complexity O(n    ))		

First: ```first(List * list)``` returns a void pointer to the data from the head of the list.       		

Rest: ```rest(List * list)``` - returns List pointer to the tail of the list.    	

Nth element: ```nth(List * list, int n)``` - returns void pointer to the data at the nth place of the listt.    
Complexity O(n).    	

Reverse: ```reverse(List * list, size_t data_size)``` - returns pointer to the List - reversed     
argument. Complexity O(n).		


Also various print functions and apriopriate get data functions, which is up to caller to choose them properly.     	

Example:    
```print_list(list, print_int);``` - prints when ```list``` is an integer list. Currently:    	

- int;	    
- long;     
- float; 	   
- char;    	

```get_long(void * ptr)``` - returns ptr cast to ```long```. Also only above data types are implemented. 		



