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
		strlen(SPACE) * 5 +
		strlen(COMMA) * 2 +
		strlen(LABEL_ID) +
		strlen(LABEL_NAME) +
		strlen(LABEL_LEVEL);
	const char * levelstr = LevelEnumToString(stu->level);
	size_t chartotal = labelLength + strlen(levelstr) + strlen(stu->name) + strlen(stu->id);
	char * result = (char*)calloc(chartotal, sizeof(char));
	strcpy_s(result, chartotal, LABEL_ID);
	strcat_s(result, chartotal, SPACE);
	strcat_s(result, chartotal, stu->id);
	strcat_s(result, chartotal, COMMA);
	strcat_s(result, chartotal, SPACE);
	strcpy_s(result, chartotal, LABEL_NAME);
	strcat_s(result, chartotal, SPACE);
	strcat_s(result, chartotal, stu->name);
	strcat_s(result, chartotal, COMMA);
	strcat_s(result, chartotal, SPACE);
	strcat_s(result, chartotal, LABEL_LEVEL);
	strcat_s(result, chartotal, SPACE);
	strcat_s(result, chartotal, levelstr);

	return result;
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

//void Add(void * p, struct LINKED_LIST * likptr) {
//	struct LINKED_LIST temp;
//	temp.content = p;
//	(*likptr).node = &temp;
//}

char * ToString(struct STUDENT * stu_ptr) {
	return nullptr;
}


