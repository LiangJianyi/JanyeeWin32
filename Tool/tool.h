#pragma once

enum LEVEL {
	LOW, MEDIUM, HIGH
};
struct STUDENT {
	const char* id;
	const char* name;
	enum LEVEL level;
};
typedef struct SIZETYPE {
	size_t value;
} SIZE_T;

const char * Fuck();
const char * StudentInfo(STUDENT * stu);
SIZE_T * NewSizeType(size_t v);