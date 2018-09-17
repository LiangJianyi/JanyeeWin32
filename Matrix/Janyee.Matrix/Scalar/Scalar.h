#pragma once
#include <typeinfo>
#include <exception>
#include <stdexcept>
namespace Janyee_Math {
	class Scalar {
	public:
		Scalar() :_value(0.0) {}
		Scalar(long double v) :_value(v) {}
		Scalar &operator=(const Scalar &scalar);
		long double Value() const;
		template<typename L, typename R> static long double Add(L left, R right) {
			int leftState = Scalar::CheckLeft(left);
			int rightState = Scalar::CheckRight(right);
			switch (leftState) {
				case -1:
					throw std::invalid_argument("Invalid left argument: ");
				case 0:
					switch (rightState) {
						case -1:
							throw std::invalid_argument("Invalid right argument: ");
						case 0:
							return left + right;
						case 1:
							return left + right.Value();
						default:
							throw std::exception("Right argument return a except value: ", rightState);
					}
				case 1:
					switch (rightState) {
						case -1:
							throw std::invalid_argument("Invalid right argument: ");
						case 0:
							return left.Value() + right;
						case 1:
							return left.Value() + right.Value();
						default:
							throw std::exception("Right argument return a except value: ", rightState);
					}
				default:
					throw std::exception("Left argument return a except value: ",leftState);
			}
		}
		template<typename L, typename R> static long double Multi(L left, R right) {
			if (Scalar::CheckLeft(left) && Scalar::CheckRight(right)) {
				return left * right;
			}
			else {
				throw std::invalid_argument("Invalid left argument: ");
			}
		}
	private:
		long double _value;
		/*
		CheckLeft 与 CheckRight 返回值含义如下：
			0：参数是内置类型
			1：参数是 Scalar 类型
			-1：参数是非内置非 Scalar 类型
		*/
		template<typename L>
		static int CheckLeft(L left) {
			if (typeid(left) == typeid(long double) ||
				typeid(left) == typeid(double) ||
				typeid(left) == typeid(float) ||
				typeid(left) == typeid(long long int) ||
				typeid(left) == typeid(long int) ||
				typeid(left) == typeid(int) ||
				typeid(left) == typeid(short) ||
				typeid(left) == typeid(unsigned long long int) ||
				typeid(left) == typeid(unsigned long int) ||
				typeid(left) == typeid(unsigned int) ||
				typeid(left) == typeid(unsigned short)) {
				return 0;
			}
			else if (typeid(left)==typeid(Scalar)) {
				return 1;
			}
			else {
				return -1;
			}
		}
		template<typename R>
		static int CheckRight(R right) {
			if (typeid(right) == typeid(long double) ||
				typeid(right) == typeid(double) ||
				typeid(right) == typeid(float) ||
				typeid(right) == typeid(long long int) ||
				typeid(right) == typeid(long int) ||
				typeid(right) == typeid(int) ||
				typeid(right) == typeid(short) ||
				typeid(right) == typeid(unsigned long long int) ||
				typeid(right) == typeid(unsigned long int) ||
				typeid(right) == typeid(unsigned int) ||
				typeid(right) == typeid(unsigned short)) {
				return 0;
			}
			else if (typeid(right)==typeid(Scalar)) {
				return 1;
			}
			else {
				return -1;
			}
		}
	};

	Scalar operator+(const Scalar &lscalar, const Scalar &rscalar);
	Scalar operator*(const Scalar &lscalar, const Scalar &rscalar);
}


