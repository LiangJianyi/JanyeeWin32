#include "LinkedList.h"
#include "tool.h"
#include <stdio.h>
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

size_t Count(LINKED_LIST * likptr) {
	size_t InsideCount(LINKED_LIST * likptr, SIZE_T * incre);
	return InsideCount(likptr, NewSizeType(0));
}

size_t InsideCount(LINKED_LIST * likptr, SIZE_T * incre) {
	if (likptr != NULL) {
		if (likptr->node != NULL) {
			incre->value += 1;
			return InsideCount(likptr->node, incre);
		}
		else {
			return incre->value;
		}
	}
	else {
		abort();
	}
}

LINKED_LIST * Remove(size_t index, LINKED_LIST * likptr) {
	printf_s("index: %d  Count(likptr): %d", index, Count(likptr));
	if (index > -1 && index < Count(likptr)) {
		if (likptr != NULL) {
			struct LINKED_LIST * releaseNode = NULL;
			if (index == 0) {
				releaseNode = likptr;
				likptr = likptr->node;
				free(releaseNode->content);
				free(releaseNode);
				return likptr;
			}
			for (size_t i = 0; i <= index; i++) {
				if (likptr->node != NULL) {
					releaseNode = likptr->node;
					likptr->node = likptr->node->node;
					free(likptr->content);
					free(likptr->node);
				}
				else {
					return likptr->node;
				}
			}
			return likptr;
		}
		else {
			abort();
		}
	}
	else {
		abort();
	}
}

void FindNodes(void * p, LINKED_LIST * likptr) {
}