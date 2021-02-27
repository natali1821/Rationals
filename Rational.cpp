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

int main() {
    Rational x; // 1/1
    Rational y(10, 5); // 10/5
    Rational z(7);

    std::cout << "x.eq(y): ";
    std::cout << x.eq(y) << std::endl;
    std::cout << "x.neq(y): ";
    std::cout << x.neq(y) << std::endl;
    std::cout << "z.neg(): ";
    z.neg().print();

    Rational n(10, 0);
    n.mul(Rational(1)).print();
    Rational(1).mul(n).print();
}
