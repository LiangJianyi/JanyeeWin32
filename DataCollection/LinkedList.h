#pragma once
struct LINKED_LIST {
	void * content;
	struct LINKED_LIST * node;
};

void Add(void * p, LINKED_LIST * likptr);
size_t Count(LINKED_LIST * likptr);
LINKED_LIST * Remove(size_t index, LINKED_LIST * likptr);
void FindNodes(void * p, LINKED_LIST * likptr);
void IndexOf(void * p, LINKED_LIST * likptr);
void First(void * p, LINKED_LIST * likptr);
void Last(void * p, LINKED_LIST * likptr);
void ForEach(LINKED_LIST * likptr, void(*func)(const char *));