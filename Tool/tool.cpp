#include "tool.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

const char * Fuck() {
	const char text[] = { 'a','p','p','l','e','\0' };
	return text;
}

const char * StudentInfo(struct STUDENT * stu) {
	const char * LevelEnumToString(LEVEL level);
	// format:
	// id: {id}, name: {name}, level: {level}\0
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
	size_t chartotal = labelLength + strlen(levelstr) + strlen(stu->name) + strlen(stu->id) + 1;
	char * result = (char*)calloc(chartotal, sizeof(char));
	strcpy_s(result, chartotal, LABEL_ID);
	strcat_s(result, chartotal, SPACE);
	strcat_s(result, chartotal, stu->id);
	strcat_s(result, chartotal, COMMA);
	strcat_s(result, chartotal, SPACE);
	strcat_s(result, chartotal, LABEL_NAME);
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

SIZE_T * NewSizeType(size_t v) {
	SIZE_T * st = (SIZE_T*)malloc(sizeof(SIZE_T));
	st->value = v;
	return st;
}


void ReadFile(char * path) {
	char buf[1024];
	FILE *file;
	size_t nread;
	errno_t err;

	err = fopen_s(&file, path, "r");
	if (file) {
		while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
			fwrite(buf, 1, nread, stdout);
		if (ferror(file)) {
			/* deal with error */
		}
		fclose(file);
	}
	printf_s("%s\n", buf);
}