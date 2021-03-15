#include <iostream>
#include "header.h"

Rational::Rational() {
    numerator = 1;
    denumerator = 1;
}

Rational::Rational(int x) {
    numerator = x;
    denumerator = 1;
}

Rational::Rational(int x, int y) {
    numerator = x;
    denumerator = y;
    nan = (y == 0);
}

int Rational::gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

Rational Rational::reduce(){
    int res = gcd(numerator, denumerator);
    return Rational(numerator / res, denumerator / res);
}

Rational Rational::neg() {
    return Rational((-1) * numerator, denumerator);
}

Rational Rational::inv() {
    return Rational(denumerator, numerator);
}

Rational Rational::sum(Rational r) {
    if (denumerator == r.denumerator) {
        return Rational(numerator + r.numerator, denumerator);
    }
    else {
        int newNumerator = numerator * r.denumerator + r.numerator * denumerator;
        int newDenumerator = denumerator * r.denumerator;
        return Rational(newNumerator, newDenumerator);
    }
}

Rational Rational::sub(Rational r) {
    return sum(r.neg());
}

Rational Rational::mul(Rational r) {
    return Rational(numerator * r.numerator, denumerator * r.denumerator);
}

Rational Rational::div(Rational r) {
    return mul(r.inv());
}

bool Rational::eq(Rational r) {
    return
        numerator == r.numerator
        &&
        denumerator == r.denumerator;
}

bool Rational::neq(Rational r) {
    return !eq(r);
}

bool Rational::l(Rational r) {
    return
        numerator * r.denumerator < r.numerator * denumerator;
}

bool Rational::leq(Rational r) {
    return
         numerator * r.denumerator <= r.numerator * denumerator;
}

bool Rational::g(Rational r) {
    return
        numerator * r.denumerator > r.numerator * denumerator;
}

bool Rational::geq(Rational r) {
    return
        numerator * r.denumerator >= r.numerator * denumerator;
}

void Rational::print() {
    if (nan) {
        std::cout << "NAN" << std::endl;
    }
    else {
        std::cout
            << numerator
            << "/"
            << denumerator
            << std::endl;
    }
}

void Rational::scan() {
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;
    std::cout << "Enter the denumerator: ";
    std::cin >> denumerator;
    nan = (denumerator == 0);
}

Rational Rational::operator+(Rational r) {
    return sum(r);
}

Rational Rational::operator-(Rational r) {
    return sub(r);
}

Rational Rational::operator*(Rational r) {
    return mul(r);
}

Rational Rational::operator/(Rational r) {
    return div(r);
}

bool Rational::operator==(Rational r) {
    return eq(r);
}

bool Rational::operator!=(Rational r) {
    return neq(r);
}
bool Rational::operator<(Rational r) {
    return l(r);
}

bool Rational::operator<=(Rational r) {
    return leq(r);
}

bool Rational::operator>(Rational r) {
    return g(r);
}

bool Rational::operator>=(Rational r) {
    return geq(r);
}

std::ostream& operator<<(std::ostream& output, const Rational& r) {
    if (r.nan) {
        output << "NAN";
    }
    else {
        output << r.numerator << "/" << r.denumerator;
    }
    return output;
}

std::istream& operator>>(std::istream& input, Rational& r) {
    input >> r.numerator >> r.denumerator;
    r.nan = (r.denumerator == 0);
    return input;
}

