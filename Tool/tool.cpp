#include "tool.h"
#include <string.h>
#include <stdlib.h>

const char * Fuck() {
	const char text[] = { 'a','p','p','l','e','\0' };
	return text;
}

const char * StudentInfo(struct STUDENT * stu) {
	const char * LevelEnumToString(LEVEL level);
	const char * SPACE = " ";
	const char * COMMA = ",";
	const char * LABEL_ID = "id:";
	const char * LABEL_NAME = "name:";
	const char * LABEL_LEVEL = "level:";
	const size_t labelLength =
		strlen(SPACE) * 2 +
		strlen(COMMA) * 2 +
		strlen(LABEL_ID) +
		strlen(LABEL_NAME) +
		strlen(LABEL_LEVEL);
	const char * levelstr = LevelEnumToString(stu->level);
	size_t charcount = labelLength + strlen(levelstr) + strlen(stu->name) + strlen(stu->id);
	char * result = (char*)calloc(charcount, sizeof(char));
	strcpy_s(result, _countof(result), charcount);

	char string[80];
	strcpy_s(string, _countof(string), "Hello world from ");
	strcat_s(string, _countof(string), "strcpy_s ");
	strcat_s(string, _countof(string), "and ");
	strcat_s(string, _countof(string), "strcat_s!");

	return nullptr;
}

const char * LevelEnumToString(LEVEL level) {
	switch (level) {
		case LOW:
			return "LOW";
		case MEDIUM:
			return "MEDIUM";
		case HIGH:
			return "HIGH";
		default:
			abort();
	}
}

void Add(void * p, struct LINKED_LIST * likptr) {
	struct LINKED_LIST temp;
	temp.content = p;
	(*likptr).node = &temp;
}

char * ToString(struct STUDENT * stu_ptr) {
	return nullptr;
}


