#ifndef H_HEADER_INCLUDED
#define H_HEADER_INCLUDED
#include <iostream>

class Rational {
public:
    bool nan;
    int numerator;
    int denumerator;

    //constructors
    Rational();
    Rational(int);
    Rational(int, int);

    //functions
    int gcd(int, int); // to realization the function reduce
    Rational reduce();
    Rational neg();  // negative, x*(-1)
    Rational inv(); // inverse, x^-1
    Rational sum(Rational);
    Rational sub(Rational);
    Rational mul(Rational);
    Rational div(Rational);

    //comparison functions
    bool eq(Rational); // "=="
    bool neq(Rational);  // "!="
    bool l(Rational);   // less than "<"
    bool leq(Rational); //// less or equal than "<="
    bool g(Rational); // greater than ">"
    bool geq(Rational); // greater or equal than ">="

    //functions of input and output
    void scan();
    void print();

    //operators
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
    bool operator==(Rational);
    bool operator!=(Rational);
    bool operator<(Rational);
    bool operator<=(Rational);
    bool operator>(Rational);
    bool operator>=(Rational);
};
std::ostream& operator<<(std::ostream&, const Rational&);
std::istream& operator>>(std::istream&, Rational&);

#endif // H_HEADER_INCLUDED

