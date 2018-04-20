#pragma once
#include <time.h>
#include <string>

namespace JanyeeWin32Sundry {
	class DateTime {
	private:
		static tm newtime;
		static time_t aclock;
		static errno_t errNum;
	public:
		DateTime() {
			// Get the number of seconds elapsed since midnight (00:00:00), January 1, 1970, UTC, according to the system clock. 
			time(&aclock);
			_localtime64_s(&newtime, &aclock);   // Convert time to struct tm form.  
		}
		static std::string DisplayCurrentTime();
		static int GetHour();
		static int IsDaylightSavingTime();
		static int GetMonthOfDay();
		static int GetMinute();
		static int GetMonth();
		static int GetSecond();
		static int GetWeekOfDay();
		static int GetYearOfDay();
		static int GetYear();
	};
}