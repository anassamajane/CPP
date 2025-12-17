#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::Fixed(int i)
{
    _value = i << _fractional_bits;
}

Fixed::Fixed(float f)
{
    _value = roundf(f * (1 << _fractional_bits));
}

float Fixed::toFloat() const
{
    return (float)_value / (1 << _fractional_bits);
}

int Fixed::toInt() const
{
    return _value >> _fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}


/* Arithmetic operators */

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_value * other._value) >> _fractional_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_value << _fractional_bits) / other._value);
    return result;
}


/* Comparison operators */

bool Fixed::operator>(const Fixed &other) const
{
    if (this->_value > other._value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &other) const
{
    if (this->_value < other._value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (this->_value >= other._value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (this->_value <= other._value)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &other) const
{
    if (this->_value == other._value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (this->_value != other._value)
        return true;
    return false;
}


/* Increment / Decrement */

Fixed &Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed copy(*this);
    this->_value++;
    return copy;
}

Fixed &Fixed::operator--()
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed copy(*this);
    this->_value--;
    return copy;
}


/* Min / Max */

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}