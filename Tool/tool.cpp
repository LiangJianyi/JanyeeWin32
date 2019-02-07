#include "tool.h"

const char * Fuck() {
	const char text[] = { 'a','p','p','l','e','\0' };
	return text;
}

void Add(void * p, struct LINKED_LIST * likptr) {
	struct LINKED_LIST temp;
	temp.content = p;
	(*likptr).node = &temp;
}
