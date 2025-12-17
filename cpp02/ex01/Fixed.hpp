#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
            int _value;
            static const int _fractional_bits = 8;

    public:
            Fixed();
            Fixed(const Fixed &other);
            Fixed &operator=(const Fixed &other);
            ~Fixed();
            Fixed(int i);
            Fixed(float f);

            float toFloat() const;
            int toInt() const;

            int getRawBits() const;
            void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif