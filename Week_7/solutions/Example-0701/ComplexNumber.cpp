#include "ComplexNumber.h"
#include <cmath>
#include <iostream>
using namespace std;

ComplexNumber::ComplexNumber(double _realPart, double _imaginaryPart)
    : realPart(_realPart), imaginaryPart(_imaginaryPart)
{
}

ComplexNumber::ComplexNumber()
    : realPart(0.0), imaginaryPart(0.0)
{
}

double ComplexNumber::GetRealPart() const
{
    return realPart;
}

double ComplexNumber::GetImaginaryPart() const
{
    return imaginaryPart;
}

void ComplexNumber::SetRealPart(double newRealPart)
{
    realPart = newRealPart;
}

void ComplexNumber::SetImaginaryPart(double newImaginaryPart)
{
    imaginaryPart = newImaginaryPart;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& rhs)
{
    realPart += rhs.realPart;
    imaginaryPart += rhs.imaginaryPart;
    return *this;
}

const ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs)
{
    return ComplexNumber(*this) += rhs;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& rhs)
{
    realPart -= rhs.realPart;
    imaginaryPart -= rhs.imaginaryPart;
    return *this;
}

const ComplexNumber ComplexNumber::operator-(const ComplexNumber& rhs)
{
    return ComplexNumber(*this) -= rhs;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& rhs)
{
    realPart = (realPart * rhs.realPart - imaginaryPart * rhs.imaginaryPart);
    imaginaryPart = (imaginaryPart * rhs.realPart + realPart * rhs.imaginaryPart);
    return *this;
}

const ComplexNumber ComplexNumber::operator*(const ComplexNumber& rhs)
{
    return ComplexNumber(*this) *= rhs;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& rhs)
{
    realPart = (realPart * rhs.realPart + imaginaryPart * rhs.imaginaryPart) / (pow(rhs.realPart, 2) + pow(rhs.imaginaryPart, 2));
    imaginaryPart = (imaginaryPart * rhs.realPart - realPart * rhs.imaginaryPart) / (pow(rhs.realPart, 2) + pow(rhs.imaginaryPart, 2));
    return *this;
}

const ComplexNumber ComplexNumber::operator/(const ComplexNumber& rhs)
{
    return ComplexNumber(*this) /= rhs;
}

const ComplexNumber ComplexNumber::operator^(int power)
{
    double newRealPart = pow((pow(realPart, 2) + pow(imaginaryPart, 2)), (power / 2) * cos(power * atan(imaginaryPart / realPart)));
    double newImaginaryPart = pow((pow(realPart, 2) + pow(imaginaryPart, 2)), (power / 2) * sin(power * atan(imaginaryPart / realPart)));
    return{ newRealPart, newImaginaryPart };
}

ComplexNumber& ComplexNumber::operator++()
{
    *this += ComplexNumber(1, 1);
    return *this;
}

const ComplexNumber ComplexNumber::operator++(int)
{
    ComplexNumber old(*this);
    ++(*this);
    return old;
}

ComplexNumber& ComplexNumber::operator--()
{
    *this -= ComplexNumber(1, 1);
    return *this;
}

const ComplexNumber ComplexNumber::operator--(int)
{
    ComplexNumber old(*this);
    --(*this);
    return old;
}

bool ComplexNumber::operator==(const ComplexNumber& rhs)
{
    return realPart == rhs.realPart && imaginaryPart == rhs.imaginaryPart;
}

bool ComplexNumber::operator!=(const ComplexNumber& rhs)
{
    return !(*this == rhs);
}

bool ComplexNumber::operator>(const ComplexNumber& rhs)
{
    double thisModule = sqrt(pow(realPart, 2) + pow(imaginaryPart, 2));
    double otherModule = sqrt(pow(realPart, 2) + pow(imaginaryPart, 2));
    return thisModule > otherModule;
}

bool ComplexNumber::operator<(const ComplexNumber& rhs)
{
    double thisModule = sqrt(pow(realPart, 2) + pow(imaginaryPart, 2));
    double otherModule = sqrt(pow(realPart, 2) + pow(imaginaryPart, 2));
    return thisModule < otherModule;
}

ComplexNumber::operator bool() const
{
    return realPart != 0 || imaginaryPart != 0;
}

std::ostream& operator<<(ostream& os, const ComplexNumber& rhs)
{
    os << rhs.realPart << " + " << rhs.imaginaryPart << "i";
    return os;
}

std::istream& operator>>(istream& is, ComplexNumber& rhs)
{
    is >> rhs.realPart >> rhs.imaginaryPart;
    return is;
}
