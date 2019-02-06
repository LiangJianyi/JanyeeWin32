#include <stdio.h>
#include <string.h>
#include "tool.h"
int main() {
	/*char text[] = { 'a','p','p','l','e' };
	char(*textp)[5] = &text;
	for (size_t i = 0; i < 5; i++) {
		printf_s("%c ", (*textp)[i]);
	}
	printf_s("\n");*/

	struct LINKED_LIST lik;
	struct STUDENT s1;
	s1.id = "s001";
	s1.name = "Janyee";
	s1.level = LOW;
	LINKED_LIST * lik_ptr = &lik;
	struct STUDENT * stu_ptr = &s1;
	printf_s("stu_ptr address: %p\n", stu_ptr);
	void * void_ptr = &s1;
	printf_s("void_ptr address: %p\n", void_ptr);
	const char * text_ptr = "fuck";
	printf_s("text_ptr address: %p  text_ptr content:%s\n", text_ptr, text_ptr);
	const void * const_void_ptr = text_ptr;
	//void_ptr = text_ptr;
	//printf_s("%p\n", lik_ptr);
	return 0;
}

void func(void * p) {
	printf("%p in func\n", p);
}

void* lsearch(void* key, void *base, int n, int elemSize) {
	for (int i = 0; i < n; ++i) {
		void *elemAddr = (char *)base + i * elemSize;/*重点，认真看这行代码*/
		if (memcmp(key, elemAddr, elemSize) == 0)
			return elemAddr;
		return NULL;
	}
}