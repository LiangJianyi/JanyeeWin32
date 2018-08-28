// Scalar.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Scalar.h"

long double Janyee_Math::Scalar::Value() const {
	return this->_value;
}
Janyee_Math::Scalar& Janyee_Math::Scalar::operator=(const Janyee_Math::Scalar &scalar) {
	this->_value = scalar.Value();
	return *this;
}

template<typename L, typename R> long double Janyee_Math::Scalar::Add(L left, R right) {
	if (Scalar::CheckLeft(left) && Scalar::CheckRight(right)) {
		return left + right;
	}
	else {
		throw std::invalid_argument("Invalid argument: " + left);
	}
}

template<typename L, typename R> long double Janyee_Math::Scalar::Multi(L left, R right) {
	if (Scalar::CheckLeft(left) && Scalar::CheckRight(right)) {
		return left * right;
	}
	else {
		throw std::invalid_argument("Invalid argument: " + left);
	}
}

Janyee_Math::Scalar Janyee_Math::operator+(const Janyee_Math::Scalar &lscalar, const Janyee_Math::Scalar &rscalar) {
	return Scalar(Janyee_Math::Scalar::Add(lscalar, rscalar));
}

Janyee_Math::Scalar Janyee_Math::operator*(const Janyee_Math::Scalar &lscalar, const Janyee_Math::Scalar &rscalar) {
	return Scalar(Janyee_Math::Scalar::Multi(lscalar, rscalar));
}
