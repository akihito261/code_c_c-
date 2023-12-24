#pragma once

class Fraction {
	int numerator;	// tử số
	int denominator; // mẫu số

public:
	Fraction(int a = 0, int b = 1) : numerator(a), denominator(b) { }

public:
	Fraction& Minimize();

public:
	friend ostream& operator<<(ostream& out, const Fraction& fraction) {
		if (fraction.numerator == 0 || fraction.denominator == 1) {
			return out << fraction.numerator;
		}
		return out << '(' << fraction.numerator << '/' << fraction.denominator << ')';
	}
	friend Fraction operator+(const Fraction& a, const Fraction& b) {
		return Fraction(
			a.numerator * b.denominator + a.denominator * b.numerator, // tử số
			a.denominator * b.denominator			// mẫu số
		);
	}
	friend bool operator==(const Fraction& a, const Fraction& b) {
		return a.numerator * b.denominator == a.denominator * b.numerator;
	}

	Fraction& operator+=(const Fraction& b) {
		return (*this = *this + b);
	}

	Fraction& operator++() {
		numerator += denominator;
		return *this;
	}

	Fraction operator++(int) {
		Fraction f(numerator, denominator);

		++(*this);
		return f;
	}

	operator double() { return (double)numerator / denominator; }
};