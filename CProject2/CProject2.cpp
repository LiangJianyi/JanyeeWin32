#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "tool.h"
#include "CProject2.h"
int main() {
	/*char text[] = { 'a','p','p','l','e' };
	char(*textp)[5] = &text;
	for (size_t i = 0; i < 5; i++) {
		printf_s("%c ", (*textp)[i]);
	}
	printf_s("\n");*/
	struct STUDENT * GetStudent(const char * id, const char * name, enum LEVEL level);
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

	NewParagraph();

	struct LINKED_LIST first;
	first.content = GetStudent("s001", "Janyee", LOW);
	first.node = NULL;

	struct LINKED_LIST second;
	second.content = GetStudent("s002", "Lee SM", MEDIUM);
	second.node = NULL;

	struct LINKED_LIST third;
	third.content = GetStudent("s003", "Wong YM", HIGH);
	third.node = NULL;

	printf_s("checkout STUDENT data:\n");
	const char * si1 = StudentInfo((STUDENT*)first.content);
	const char * si2 = StudentInfo((STUDENT*)second.content);
	const char * si3 = StudentInfo((STUDENT*)third.content);
	printf_s("first.content = %s\n", si1);
	printf_s("second.content = %s\n", si2);
	printf_s("third.content = %s\n", si3);
	free((void*)si1);
	free((void*)si2);
	free((void*)si3);

	NewParagraph();

	void PrintStudentInfo(const char * sti);
	Add(GetStudent("s002", "Lee SM", MEDIUM),
		&first);
	ForEach(&first, PrintStudentInfo);

	return 0;
}

void PrintStudentInfo(const char * sti) {
	printf_s("%s\n", sti);
}

void NewParagraph() {
	printf_s("\n");
	printf_s("\n");
	printf_s("\n");
}

STUDENT * GetStudent(const char * id, const char * name, enum LEVEL level) {
	STUDENT * stu = (STUDENT*)malloc(sizeof(STUDENT));
	stu->id = id;
	stu->name = name;
	stu->level = level;
	return stu;
};

void* lsearch(void* key, void *base, int n, int elemSize) {
	for (int i = 0; i < n; ++i) {
		void *elemAddr = (char *)base + i * elemSize;/*重点，认真看这行代码*/
		if (memcmp(key, elemAddr, elemSize) == 0)
			return elemAddr;
		return NULL;
	}
}