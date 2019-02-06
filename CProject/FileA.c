#include <stdio.h>

enum LEVEL {
	LOW, MEDIUM, HIGH
};

struct STUDENT {
	const char* id;
	const char* name;
	enum LEVEL level;
};

int main() {
	FILE * fp;
	errno_t err;
	//struct STUDENT;

	err = fopen_s(&fp, "C:\\Users\\a124p\\Desktop\\fuck.txt", "w+");
	if (err==0) {
		printf_s("file.txt is created.\n");
		printf_s("writing.......\n");
		struct STUDENT s1, s2, s3;
		s1.id = "s001";
		s1.name = "Janyee";
		s1.level = LOW;
		s2.id = "s002";
		s2.name = "LiSm";
		s2.level = MEDIUM;
		s3.id = "s003";
		s3.name = "Luke Skyworker";
		s3.level = HIGH;
		fprintf_s(fp, "s1:\n");
		fprintf_s(fp, "id=%s  name=%s  level=%d\n", s1.id, s1.name, s1.level);
		fprintf_s(fp, "s2:\n");
		fprintf_s(fp, "id=%s  name=%s  level=%d\n", s2.id, s2.name, s2.level);
		fprintf_s(fp, "s3:\n");
		fprintf_s(fp, "id=%s  name=%s  level=%d\n", s3.id, s3.name, s3.level);
		printf_s("write end.\n");
	}
	else {
		printf_s("error code: %d", err);
	}

	fclose(fp);
	return 0;
}

void file_io(const char* const path,const char* const mode,char (*line)[]) {
	FILE * fp;
	errno_t err;

}