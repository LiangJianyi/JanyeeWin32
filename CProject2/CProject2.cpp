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
	struct STUDENT * stu_ptr = GetStudent("s001", "Janyee", LOW);
	printf_s("stu_ptr address: %p\n", stu_ptr);
	void * void_ptr = stu_ptr;
	printf_s("void_ptr address: %p\n", void_ptr);
	const char * text_ptr = "fuck";
	printf_s("text_ptr address: %p  text_ptr content:%s\n", text_ptr, text_ptr);
	const void * const_void_ptr = text_ptr;
	//void_ptr = text_ptr;
	//printf_s("%p\n", lik_ptr);

	printf_s("\n");
	printf_s("\n");
	printf_s("\n");

	struct LINKED_LIST first;
	first.content = GetStudent("s001", "Janyee", LOW);
	return 0;
}

struct STUDENT * GetStudent(const char * id, const char * name, enum LEVEL level) {
	struct STUDENT stu;
	stu.id = id;
	stu.name = name;
	stu.level = level;
	return &stu;
};

void* lsearch(void* key, void *base, int n, int elemSize) {
	for (int i = 0; i < n; ++i) {
		void *elemAddr = (char *)base + i * elemSize;/*重点，认真看这行代码*/
		if (memcmp(key, elemAddr, elemSize) == 0)
			return elemAddr;
		return NULL;
	}
}