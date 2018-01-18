#include <iostream>
#include <string>
#include <time.h>

using namespace std;

tm newtime;
time_t aclock;
int main() {
	char buffer[32];
	int errNum;
	// Get the number of seconds elapsed since midnight (00:00:00), January 1, 1970, UTC, according to the system clock. 
	time(&aclock);
	_localtime64_s(&newtime, &aclock);   // Convert time to struct tm form.  

										 // Print local time as a string.  

	// Convert time to string form
	errNum = asctime_s(buffer, 32, &newtime);
	if (errNum)
	{
		cout << "Error code: %d" << (int)errNum << endl;
		return 1;
	}

	cout << "Current date and time: %s" << buffer << endl;
	cout << newtime.tm_hour << endl;
	cout << newtime.tm_isdst << endl;
	cout << newtime.tm_mday << endl;
	cout << newtime.tm_min << endl;
	cout << newtime.tm_mon << endl;
	cout << newtime.tm_sec << endl;
	cout << newtime.tm_wday << endl;
	cout << newtime.tm_yday << endl;
	cout << newtime.tm_year << endl;

	cout << endl;

	time_t localTime;
	cout << time(&localTime) << endl;
	
	system("pause");
	return 0;
}

void action() {
	//cout << obj << endl;
}

struct PERSON {   // Declare PERSON struct type  
	int age;   // Declare member types  
	long ss;
	float weight;
	char name[25];
} family_member;   // Define object of type PERSON  

struct CELL {   // Declare CELL bit field  
	unsigned short character : 8;  // 00000000 ????????  
	unsigned short foreground : 3;  // 00000??? 00000000  
	unsigned short intensity : 1;  // 0000?000 00000000  
	unsigned short background : 3;  // 0???0000 00000000  
	unsigned short blink : 1;  // ?0000000 00000000  
} screen[25][80];       // Array of bit fields   