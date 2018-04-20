#pragma once
extern "C" {
#include <time.h>
}
#include <string>
// MathFuncsLib.h

namespace MathFuncs {
	class MyMathFuncs {
	public:
		// Returns a + b
		static double Add(double a, double b);

		// Returns a - b
		static double Subtract(double a, double b);

		// Returns a * b
		static double Multiply(double a, double b);

		// Returns a / b
		static double Divide(double a, double b);
	};
}

namespace JanyeeWin32Sundry {
	extern "C" static tm newtime;
	extern "C" static errno_t errNum;
	class DateTime {
	private:
		static time_t aclock;
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