#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed::Fixed(int i)
{
    std::cout << "Int constructor called\n";
    _value = i << _fractional_bits;
}

Fixed::Fixed(float f)
{
    std::cout << "Float constructor called\n";
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
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}