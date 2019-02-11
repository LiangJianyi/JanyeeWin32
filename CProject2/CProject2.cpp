#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "tool.h"
#include "CProject2.h"
#include "LinkedList.h"

int main() {
	struct STUDENT * GetStudent(const char * id, const char * name, enum LEVEL level);
	struct STUDENT * stu_ptr = GetStudent("s001", "Janyee", LOW);
	printf_s("stu_ptr address: %p\n", stu_ptr);
	void * void_ptr = stu_ptr;
	printf_s("void_ptr address: %p\n", void_ptr);
	const char * text_ptr = "fuck";
	printf_s("text_ptr address: %p  text_ptr content:%s\n", text_ptr, text_ptr);
	const void * const_void_ptr = text_ptr;

	NewParagraph();

	void PrintStudentInfo(const char * sti);
	struct LINKED_LIST first;
	first.content = GetStudent("s001", "Janyee", LOW);
	first.node = NULL;

	Add(GetStudent("s002", "Lee SM", MEDIUM), &first);
	Add(GetStudent("s003", "Wong YUYan", HIGH), &first);
	Add(GetStudent("s004", "Wong Xinyu", HIGH), &first);
	Add(GetStudent("s005", "Zhao Linyue", MEDIUM), &first);
	Add(GetStudent("s006", "Phoebe Kilminster", HIGH), &first);
	ForEach(&first, PrintStudentInfo);
	printf_s("Count of LinkedList: %d\n", Count(&first));

	NewParagraph();

	printf_s("Remove index 0:\n");
	first = *Remove(0, &first);
	ForEach(&first, PrintStudentInfo);
	printf_s("Count of LinkedList: %d\n\n", Count(&first));
	printf_s("Remove index 1:\n");
	first = *Remove(1, &first);
	ForEach(&first, PrintStudentInfo);
	printf_s("Count of LinkedList: %d\n\n", Count(&first));
	printf_s("Remove index 2:\n");
	first = *Remove(2, &first);
	ForEach(&first, PrintStudentInfo);
	printf_s("Count of LinkedList: %d\n\n", Count(&first));
	printf_s("Remove index 3:\n");
	first = *Remove(3, &first);
	ForEach(&first, PrintStudentInfo);
	printf_s("Count of LinkedList: %d\n\n", Count(&first));
	printf_s("Remove index 4:\n");
	first = *Remove(4, &first);
	ForEach(&first, PrintStudentInfo);
	printf_s("Count of LinkedList: %d\n\n", Count(&first));
	printf_s("Remove index 5:\n");
	first = *Remove(5, &first);
	ForEach(&first, PrintStudentInfo);
	printf_s("Count of LinkedList: %d\n\n", Count(&first));
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