// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "datetime.h"
#include "MathFuncsLib.h"

using namespace std;
int main() {
	cout << JanyeeWin32Sundry::DateTime::DisplayCurrentTime() << endl;
	double a = 7.4;
	int b = 99;

	cout << "a + b = " <<
		MathFuncs::MyMathFuncs::Add(a, b) << endl;
	cout << "a - b = " <<
		MathFuncs::MyMathFuncs::Subtract(a, b) << endl;
	cout << "a * b = " <<
		MathFuncs::MyMathFuncs::Multiply(a, b) << endl;
	cout << "a / b = " <<
		MathFuncs::MyMathFuncs::Divide(a, b) << endl;
	
	return 0;
}

