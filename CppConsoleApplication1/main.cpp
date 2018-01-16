#include <iostream>
#include <ctime>
#include<stdio.h>
#include<time.h>

using namespace std;

struct tm newtime;
__time32_t aclock;
int main() {
	char buffer[32];
	errno_t errNum;
	_time32(&aclock);   // Get time in seconds.  
	_localtime32_s(&newtime, &aclock);   // Convert time to struct tm form.  

										 // Print local time as a string.  

	errNum = asctime_s(buffer, 32, &newtime);
	if (errNum)
	{
		printf("Error code: %d", (int)errNum);
		return 1;
	}
	printf("Current date and time: %s", buffer);
	system("pause");
	return 0;
}