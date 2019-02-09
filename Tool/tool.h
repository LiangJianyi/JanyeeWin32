#pragma once
struct LINKED_LIST {
	struct STUDENT * content;
	struct LINKED_LIST * node;
};
enum LEVEL {
	LOW, MEDIUM, HIGH
};
struct STUDENT {
	const char* id;
	const char* name;
	enum LEVEL level;
};
const char * Fuck();
void Add(void * p, struct LINKED_LIST * likptr);
void Remove(void * p, struct LINKED_LIST * likptr);
void Find(void * p, struct LINKED_LIST * likptr);
void IndexOf(void * p, struct LINKED_LIST * likptr);
void First(void * p, struct LINKED_LIST * likptr);
void Last(void * p, struct LINKED_LIST * likptr);
const char * StudentInfo(struct STUDENT * stu);
char * ToString(struct STUDENT * stu_ptr);