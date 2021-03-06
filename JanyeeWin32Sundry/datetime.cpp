#include <time.h>
#include <string>
#include "datetime.h"
//#include <stdafx.h>

namespace JanyeeWin32Sundry {
	std::string DateTime::DisplayCurrentTime() {
		char buffer[64];
		errNum = asctime_s(buffer, 64, &newtime);
		if (errNum) {
			return std::string("Error code: ").append(std::to_string(errNum));
		}
		else {
			return buffer;
		}
	}
	int DateTime::GetHour() {
		return newtime.tm_hour;
	}
	int DateTime::IsDaylightSavingTime() {
		return newtime.tm_isdst;
	}
	int DateTime::GetMonthOfDay() {
		return newtime.tm_mday;
	}
	int DateTime::GetMinute() {
		return newtime.tm_min;
	}
	int DateTime::GetMonth() {
		return newtime.tm_hour;
	}
	int DateTime::GetSecond() {
		return newtime.tm_sec;
	}
	int DateTime::GetWeekOfDay() {
		return newtime.tm_wday;
	}
	int DateTime::GetYearOfDay() {
		return newtime.tm_yday;
	}
	int DateTime::GetYear() {
		return newtime.tm_year;
	}
}