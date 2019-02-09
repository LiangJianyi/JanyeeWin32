#pragma once
struct LINKED_LIST {
	void * content;
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
void Add(void * p, LINKED_LIST * likptr);
size_t Count(LINKED_LIST * likptr);
void Remove(size_t index, LINKED_LIST * likptr);
void FindNodes(void * p, LINKED_LIST * likptr);
void IndexOf(void * p, LINKED_LIST * likptr);
void First(void * p, LINKED_LIST * likptr);
void Last(void * p, LINKED_LIST * likptr);
void ForEach(LINKED_LIST * likptr, void(*func)(const char *));
const char * StudentInfo(STUDENT * stu);