#include "tool.h"
#include <string.h>
#include <stdlib.h>

const char * Fuck() {
	const char text[] = { 'a','p','p','l','e','\0' };
	return text;
}

void ForEach(LINKED_LIST * likptr, void(*func)(const char *)) {
	if (likptr != NULL) {
		func(StudentInfo((struct STUDENT *)likptr->content));
		ForEach(likptr->node, func);
	}
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

void Remove(size_t index, LINKED_LIST * likptr) {
	if (index > 0) {
		for (size_t i = 0; i < index - 1; i++) {
			likptr = likptr->node;
		}
		free(likptr->node);
		likptr->node = likptr->node->node;
	}
	else if (index == 0) {
		likptr = likptr->node;
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


