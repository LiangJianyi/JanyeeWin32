#pragma once
#include <typeinfo>
namespace Janyee_Math {
	class Scalar {
	public:
		Scalar() :_value(0.0) {}
		Scalar(long double v) :_value(v) {}
		Scalar &operator=(const Scalar &scalar);
		long double Value() const;
		template<typename L, typename R> static long double Add(L left, R right);
		template<typename L, typename R> static long double Multi(L left, R right);
	private:
		long double _value;
		template<typename L>
		static bool CheckLeft(L left) {
			return typeid(left) == typeid(long double) ||
				typeid(left) == typeid(double) ||
				typeid(left) == typeid(float) ||
				typeid(left) == typeid(long long int) ||
				typeid(left) == typeid(long int) ||
				typeid(left) == typeid(int) ||
				typeid(left) == typeid(short) ||
				typeid(left) == typeid(unsigned long long int) ||
				typeid(left) == typeid(unsigned long int) ||
				typeid(left) == typeid(unsigned int) ||
				typeid(left) == typeid(unsigned short) ||
				typeid(left) == typeid(Scalar);
		}
		template<typename R>
		static bool CheckRight(R right) {
			return typeid(right) == typeid(long double) ||
				typeid(right) == typeid(double) ||
				typeid(right) == typeid(float) ||
				typeid(right) == typeid(long long int) ||
				typeid(right) == typeid(long int) ||
				typeid(right) == typeid(int) ||
				typeid(right) == typeid(short) ||
				typeid(right) == typeid(unsigned long long int) ||
				typeid(right) == typeid(unsigned long int) ||
				typeid(right) == typeid(unsigned int) ||
				typeid(right) == typeid(unsigned short) ||
				typeid(right) == typeid(Scalar);
		}
	};

	Scalar operator+(const Scalar &lscalar, const Scalar &rscalar);
	Scalar operator*(const Scalar &lscalar, const Scalar &rscalar);
}


