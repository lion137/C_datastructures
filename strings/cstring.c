/*
copyright 2019 lion137
MIT license:
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
documentation files (the "Software"), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
* 
* 
* 
* 

Constant size string implementation(const size char array under the hood); max_size = 10000, could be changed by 
 manual manipulation
Name of structure: cstring.
Constructor of empty string(returns pointer): constructor.
Freeing memory: clear_cstring(<address of cstring>).

Other methods, if not stated differently, time complexity is O(1): 
 - append(char) - at the end;
 - pop(cstring) - from the end;
 - len(cstring);
 - isEmpty(cstring);
 - concat(cstring, cstring) - void mutates the first argument, O(len(n)) - here n = length of the second string;
 - isCharAt(cstring, char) - returns index of first occurence char in string, -1 otherwise, O(n);
 - setCharAt(cstring, int index);
 - deleteCharAt(cstring, int index) - O(n);
 - insertAt(cstring, int index, char) inserts char before index, O(n);
 - isSubstring(cstring l, cstring r) - returns 1 if r is substring of l, 0 othervise, O(n), n - length of r;
 - isEqual(cstring, cstring) - O(n);
 - reversed(cstring) - void, O(n);
 - toUpper, toLower - O(n).
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define max_size 10000

typedef struct {
	int size;
	char  st[max_size];
}cstring;


cstring * construct() {
	cstring * o = (cstring *) (malloc(sizeof(cstring)));
	if (o == NULL) {
		fprintf(stderr, "%s", "cstring, constructor: Malloc failed!\n");
		abort();
	}
	o->size = 0;
	
	return o;
}

void clear_cstring(cstring ** ptr) {
	if (*ptr != NULL){
		free(*ptr);
		*ptr = NULL;
	}
}

int len(cstring * s) {return s->size;}

int isEmpty(cstring * s) {return s->size == 0;}

void append(cstring * e, char c) {
	if (len(e) >= max_size - 1) {
		fprintf(stderr, "append: index out of range!\n");
		abort();
	}
	e->st[e->size++] = c;
}

char pop(cstring * e) {
	if (isEmpty(e)) {
		fprintf(stderr, "Pop empty cstring ");
		abort();
	}
	char tmp = e->st[len(e) - 1];
	e->st[len(e) - 1] = '\0';
	--(e->size);
	return tmp;
}


char charAt(cstring * p, int i) {
	if (isEmpty(p)) {
		fprintf(stderr, "charAt: empty string!\n");
		abort();
	}
	if (i < 0 || (i >= len(p))){
		fprintf(stderr, "charAt: index out of range!\n");
		abort();
	}
	return p->st[i];
}

void  concat(cstring * left, cstring * right) {
	if ((len(left) + len(right)) >= max_size){
		fprintf(stderr, "concat: concatenated string out of range!\n");
		abort();
	}
	if (! (isEmpty(right) || isEmpty(left))){
	int l1 = len(left);
	int l2 = len(right);
	for (int i = l1; i < l2 + l1; ++i)
		left->st[i] = right->st[i - l1];
	left->size += l2;
	}
}

int isCharIn(cstring * p, char c) {
	for (int i = 0; i < len(p); ++i){
		if (p->st[i] == c) {
			return i;
		}
	}
	return -1;
}

void setCharAt(cstring * p, int i, char c) {
	if ( i < 0 || (i >= len(p)) ) {
			fprintf(stderr, "setCharAt: index out of range!\n");
			abort();
	}
	p->st[i] = c;
}

// helper function
static void __move_cover(cstring * p, int i) {
	int limit = len(p) - 1;
	for (int j = i; j <= limit; ++j)
		p->st[j] = p->st[j + 1];
}

void deleteAt(cstring * p, int i) {
		if ( i < 0 || (i >= len(p)) ) {
			fprintf(stderr, "deleteCharAt: index out of range!\n");
			abort();
	}
	__move_cover(p, i);
	--(p->size);
}

//helper
static void __move_to_insert(cstring * p, int i){
	int limit = len(p);
	for (int j = limit; j >= i; --j){
		p->st[j] = p->st[j - 1];
	}
}

void insertAt(cstring * p, int i, char c) {
	assert (len(p) < max_size - 1);
	assert (i >= 0 && i <= len(p));
	
	if (isEmpty(p)) {
			p->st[i] = c;
		++(p->size);
	}
	else {
	__move_to_insert(p, i);
	p->st[i] = c;
	++(p->size);
	}
}

int isSubstring(cstring * l, cstring * r) {
	if (isEmpty(r)) return 1;
	if (isEmpty(l)) return 0;
	char * str1 = l->st;
	char * str2 = r->st;
	if (strstr(str1, str2))
		return 1;
	else
		return 0;
}

int isEqual(cstring * l, cstring * r) {
	if (isEmpty(l) && isEmpty(r)) return 1;
	if (isEmpty(l)) return 0;
	if (isEmpty(r)) return 0;
	char * str1 = l->st;
	char * str2 = r->st;
	size_t num;
	if (strlen(str1) >= strlen(str2)) num = (size_t) strlen(str1);
	else num = strlen(str2);
	if (strncmp(str1, str2, num) == 0) return 1;
	else return 0;
}

void reversed(cstring * p){
	if (isEmpty(p)) return;
	else {
		char tmp[max_size];
		for (int k = 0; k < len(p); ++k)
			tmp[k] = p->st[k];
		int i = len(p) - 1;
		int k = 0;
		while (i >= 0) {
			p->st[k] = tmp[i];
			k += 1;
			i -= 1;

		}
	}
}

void toUpper(cstring * p) {
	if (! isEmpty(p)) {
		int limit = len(p);
		for (int i = 0; i < limit; ++i) 
			p->st[i] = toupper(p->st[i]);
	}
}

void toLower(cstring * p) {
	if (! isEmpty(p)) {
		int limit = len(p);
		for (int i = 0; i < limit; ++i) 
			p->st[i] = tolower(p->st[i]);
	}
}

//tests
void tests(void);

//debugging
void print_string(cstring * p) {
	if (! isEmpty(p))
		printf("%s len=%i\n", p->st, len(p));
	else 
		printf("%s len=%i\n", "", len(p));
}

int main() {

	tests();
	
	return 0;
}




void tests(void) {
	puts("------TESTS----------");
	cstring * s1 = construct();
	puts("Len of empty");
	assert (len(s1) == 0);
	puts("isEmpty of empty");
	assert (isEmpty(s1));
	append(s1, 'a');
	puts("Len of 1 == 1");
	assert(len(s1) == 1);
	puts("push pop in loop");
	for (int i = 0; i < 9000; ++i){
		append(s1, 'z');
	}
	for (int i = 0; i < 9000; ++i){
		pop(s1);
	}
	assert (len(s1) == 1);
	
	
	puts("charAt");
	assert(charAt(s1, 0) == 'a');
	append(s1, 'b');
	append(s1, 'c');
	assert (charAt(s1, 2) == 'c');
	assert (pop(s1) == 'c');
	
	
	puts("concat");
	cstring * s2 = construct();
	append(s2, 'c');
	concat(s1, s2);
	assert ( charAt(s1, 0) == 'a' && charAt(s1, 1) == 'b' && charAt(s1, 2) == 'c');
	assert(len(s1) == 3);
	assert(len(s2) == 1);
	pop(s1);
	assert (len(s1) == 2);
	cstring * s3 = construct();
	cstring * s4 = construct();
	assert(isEmpty(s3) && isEmpty(s4));
	concat(s3, s4);
	assert(isEmpty(s3) && isEmpty(s4));
	puts("isCharIn");
	assert( isCharIn(s1, 'a') == 0);
	assert(-1 == (isCharIn(s1, 'z')));
	pop(s2);
	assert ( (isCharIn(s2, 'c')) == -1);
	free(s3);
	free(s4);
	
	puts("setCharAt");
	setCharAt(s1, 1, 'B');
	assert(charAt(s1, 1) == 'B');

	puts("deleteAt");
	deleteAt(s1, 1);
	assert (len(s1) == 1);
	assert (s1->st[0] == 'a');
	deleteAt(s1, 0);
	assert (len(s1) == 0);
	assert (s1->st[0] == '\0');
	
	puts("insertAt");
	append(s1, 'a');
	append(s1, 'b');
	append(s1, 'c');
	insertAt(s1, 0, 'A');
	assert(charAt(s1, 0) == 'A');
	deleteAt(s1, 0);
	insertAt(s1, 1, 'A');
	assert(charAt(s1, 1) == 'A');
	insertAt(s1, 4, 'B');
	assert(charAt(s1, 4) == 'B');
	assert (len(s1) == 5);
	append(s2, 'a');
	pop(s2);
	insertAt(s2, 0, 'a');
	assert(charAt(s2, 0) == 'a');
	
	puts("isSubstring");
	assert(isSubstring(s1, s2));
	assert(isSubstring(s1, construct()));
	assert(! isSubstring(construct(), s2));
	assert(! isSubstring(s2, s1));
	print_string(s1);
	print_string(s2);
	
	puts("isEqual");
	assert(! isEqual(s1, s2));
	assert( isEqual(construct(), construct()));
	assert(! isEqual(construct(), s1));
	assert(! isEqual(s2, construct()));
	cstring * s5 = construct();
	cstring * s6 = construct();
	append(s5, 'a');
	append(s6, 'a');
	assert (isEqual(s5, s6));
	append(s6, 'a');
	assert(! isEqual(s5, s6));
	free(s5);
	free(s6);


	puts("reversed");
	cstring * s7 = construct();
	append(s7, 'a');
	append(s7, 'b');
	append(s7, 'c');
	reversed(s7);
	assert (charAt(s7, 0) == 'c' && charAt(s7, 1) == 'b' && charAt(s7, 2) == 'a');
	clear_cstring(&s7);
	
	puts("toUpper");
	cstring * s8 = construct();
	append(s8, 'A');
	append(s8, 'b');
	append(s8, 'c');
	toUpper(s8);
	assert(charAt(s8, 0) == 'A' && charAt(s8, 1) == 'B' && charAt(s8, 2) == 'C');
	clear_cstring(&s8);
	
	
	puts("toLower");
	cstring * s9 = construct();
	append(s9, 'A');
	append(s9, 'B');
	append(s9, 'c');
	toLower(s9);
	assert(charAt(s9, 0) == 'a' && charAt(s9, 1) == 'b' && charAt(s9, 2) == 'c');	
	

	puts("Proberly cleaned");
	clear_cstring(&s1);
	assert (! s1);
	puts("------TESTS PASSED!---");
}
