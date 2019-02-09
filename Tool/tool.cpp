#include "tool.h"
#include <string.h>

const char * Fuck() {
	const char text[] = { 'a','p','p','l','e','\0' };
	return text;
}

//const char * StudentInfo(struct STUDENT * stu) {
//	const char * space = " ";
//	const char * colon = ":";
//	char result[] = "id: ";
//	//result = strcat(result, stu->id);
//}

void Add(void * p, struct LINKED_LIST * likptr) {
	struct LINKED_LIST temp;
	temp.content = p;
	(*likptr).node = &temp;
}
