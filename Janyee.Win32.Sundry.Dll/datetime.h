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
		static std::string DisplayCurrentTime() {
			char buffer[64];
			errNum = asctime_s(buffer, 64, &newtime);
			if (errNum) {
				return std::string("Error code: ").append(std::to_string(errNum));
			}
			else {
				return buffer;
			}
		}
		static int GetHour() {
			return newtime.tm_hour;
		}
		static int IsDaylightSavingTime() {
			return newtime.tm_isdst;
		}
		static int GetMonthOfDay() {
			return newtime.tm_mday;
		}
		static int GetMinute() {
			return newtime.tm_min;
		}
		static int GetMonth() {
			return newtime.tm_hour;
		}
		static int GetSecond() {
			return newtime.tm_sec;
		}
		static int GetWeekOfDay() {
			return newtime.tm_wday;
		}
		static int GetYearOfDay() {
			return newtime.tm_yday;
		}
		static int GetYear() {
			return newtime.tm_year;
		}
	};
}