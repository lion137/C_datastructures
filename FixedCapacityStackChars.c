// Fixed capacity stack of characters
#include <stdio.h>
#include <stdlib.h>

typedef struct StackChars{
    char * tab;
    int top;
    int capacity;
}StackChars;

StackChars *  new_s(int size){
	StackChars * obj = (StackChars * ) malloc(sizeof(StackChars));
	if (obj == NULL) {
		fprintf(stderr, "%s", "linked_list, constructor: Malloc failed!\n");
		abort();
	}
	obj->tab = malloc (size * (sizeof(char)));
	obj->top = 0;
	obj->capacity = size;
	return obj;
};

int isEmpty(StackChars * s){
    return s->top == 0;
}

int isFull(StackChars * s){
    return s->top >= s->capacity;
}

void push(StackChars * s , char c){
    if (isFull(s)){
		fprintf(stderr, "%s", "StackChars! Error, stack is full!\n");
    }
    else{
        s->tab[s->top++] = c;
    }
}

char pop(StackChars * s)
{
    if (isEmpty(s))
		fprintf(stderr, "%s", "StackChars! Error, stack is empty!\n");
    else
        return s->tab[--s->top];
}
int peek(StackChars * s)
{
    return s->tab[s->top - 1];
}

void print_stack(StackChars * s) {
    for (int i = 0; i < s->top; i++) {
        printf("%c ", s->tab[i]);
        }
     printf("\n");
}



int main() {
	StackChars * s = new_s(2);
	push(s, 'b');
	push(s, 'c');
	printf("%d\n", isEmpty(s));
	printf("%d\n", isFull(s));
	push(s, 'a');
	print_stack(s);
	pop(s);
	print_stack(s);
	printf("%c\n", peek(s));
	pop(s);
	pop(s);
	return 0;
}
