#pragma once

enum LEVEL {
	LOW, MEDIUM, HIGH
};
struct STUDENT {
	const char* id;
	const char* name;
	enum LEVEL level;
};
const char * Fuck();
const char * StudentInfo(STUDENT * stu);