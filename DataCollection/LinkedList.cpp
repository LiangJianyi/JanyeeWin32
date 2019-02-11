#include "LinkedList.h"
#include "tool.h"
#include <stdlib.h>

void ForEach(LINKED_LIST * likptr, void(*func)(const char *)) {
	if (likptr != NULL) {
		func(StudentInfo((struct STUDENT *)likptr->content));
		ForEach(likptr->node, func);
	}
}
void Add(void * content, struct LINKED_LIST * likptr) {
	struct LINKED_LIST * temp = (struct LINKED_LIST*)malloc(sizeof(struct LINKED_LIST));
	temp->content = content;
	temp->node = NULL;
	if (likptr->node == NULL) {
		likptr->node = temp;
	}
	else {
		Add(content, likptr->node);
	}
}

size_t $Increment = 0;
size_t Count(LINKED_LIST * likptr) {
	if (likptr != NULL) {
		if (likptr->content != NULL) {
			$Increment += 1;
			return Count(likptr->node);
		}
	}
	else {
		return $Increment;
	}
}

LINKED_LIST * Remove(size_t index, LINKED_LIST * likptr) {
	if (index > 0) {
		LINKED_LIST * releaseNode = likptr->node;
		likptr->node = likptr->node->node;
		free(releaseNode);
		return likptr;
	}
	else if (index == 0) {
		return likptr->node;
	}
	else if (index > Count(likptr) - 1) {
		abort();
	}
	else {
		abort();
	}
}

void FindNodes(void * p, LINKED_LIST * likptr) {
}