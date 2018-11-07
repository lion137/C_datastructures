### Generic Linked List (via void pointers)

Usage(linux): put ```linked_list_generic.h```, ```print_lists.h``` and ```list_functions.h``` somewhere in Path or working directory.           
Tests: in a directory linked_list_generic run: ```./tests.sh``` or ```<your shell> tests.sh``` if you shell is not ```/bin/bash```    
Compiles: ```gcc -std=c99```    

API:    

If not explicitly stated: mutates and/or complexity, assuming doesn't ' mutate original object and  complexity = O(1).

constructor: ``` Linked_list_generic * linked_list_init()```    
add element to list: ```void add(Linked_list_generic * ptr, int elem)``` mutates           
pop: ```void pop(Linked_list_generic * ptr)```    mutates        
size: ```size_t len(Linked_list_generic * ptr)```         
empty?: ```bool is_empty(Linked_list_generic * ptr)``` - This one works only in ```C99```, but could be easily fixed,.     
Cons: ```cons(void * data, size_t data_size, Linked_list_generic * ptr)``` and returns new list with data element prependded
to list.    
Insert: ```insert(Linked_list_generic * list, void * data, size_t data_size, int n)``` - mutates a list, returns element    
```data``` insertred after ```n```-th element of the list, append at the end when supplied with ```n = -1```. Complexity O(n    ))
First: ```first(Linked_list_generic * list)``` returns a void pointer to the data from the head of the list.       
Rest: ```rest(Linked_list_generic * list)``` - returns Linked_list_generic pointer to the tail of the list.    
Nth element: ```nth(Linked_list_generic * list, int n)``` - returns void pointer to the data at the nth place of the listt.    
Complexity O(n).    
Reverse: ```reverse(Linked_list_generic * list, size_t data_size)``` - returns pointer to the Linked_list_generic - reversed     
argument. Complexity O(n).    

Also various print functions and apriopriate get data functions, which is up to caller to choose them properly.     
Example:    
```print_list(list, print_int);``` - prints when ```list``` is an integer list. Currently:    
- int;    
- long;    
- float;    
- char;    

```get_long(void * ptr)``` - returns ptr cast to ```long```. Also only above data types are implemented. 	



