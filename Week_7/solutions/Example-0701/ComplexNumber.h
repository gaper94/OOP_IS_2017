#ifndef COMPLEX_H
#define COMPLEX_H

#include <iosfwd> // forward declarations for istream & ostream

class ComplexNumber
{
public:
    ComplexNumber(double realPart, double imaginaryPart);
    ComplexNumber();
    ComplexNumber(const ComplexNumber& other) = default;

    // Getters
    double GetRealPart() const;
    double GetImaginaryPart() const;
    // Setter
    void SetRealPart(double newRealPart);
    void SetImaginaryPart(double newImaginaryPart);
    
    // Overloaded operators
    ComplexNumber& operator=(const ComplexNumber&) = default;

    ComplexNumber& operator+=(const ComplexNumber& rhs);
    const ComplexNumber operator+(const ComplexNumber& rhs);

    ComplexNumber& operator-=(const ComplexNumber& rhs);
    const ComplexNumber operator-(const ComplexNumber& rhs);

    ComplexNumber& operator*=(const ComplexNumber& rhs);
    const ComplexNumber operator*(const ComplexNumber& rhs);

    ComplexNumber& operator/=(const ComplexNumber& rhs);
    const ComplexNumber operator/(const ComplexNumber& rhs);

    const ComplexNumber operator^(int power);

    ComplexNumber& operator++();
    const ComplexNumber operator++(int);

    ComplexNumber& operator--();
    const ComplexNumber operator--(int);

    bool operator==(const ComplexNumber& rhs);
    bool operator!=(const ComplexNumber& rhs);

    bool operator>(const ComplexNumber& rhs);
    bool operator<(const ComplexNumber& rhs);

    operator bool() const;

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& rhs);
    friend std::istream& operator>>(std::istream& is, ComplexNumber& rhs);

private:
    double realPart;
    double imaginaryPart;
};
#endif // COMPLEX_H