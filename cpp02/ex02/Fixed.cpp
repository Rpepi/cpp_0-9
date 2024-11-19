/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepi <pepi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:04:16 by pepi              #+#    #+#             */
/*   Updated: 2024/11/19 11:08:18 by pepi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    value = n << fractional_bits;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(n * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)value / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return value >> fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const { return value > other.value; }
bool Fixed::operator<(const Fixed &other) const { return value < other.value; }
bool Fixed::operator>=(const Fixed &other) const { return value >= other.value; }
bool Fixed::operator<=(const Fixed &other) const { return value <= other.value; }
bool Fixed::operator==(const Fixed &other) const { return value == other.value; }
bool Fixed::operator!=(const Fixed &other) const { return value != other.value; }

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(value + other.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(value - other.value);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((value * other.value) >> fractional_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.value == 0)
        throw std::runtime_error("Division by zero");
    Fixed result;
    result.setRawBits((value << fractional_bits) / other.value);
    return result;
}

Fixed &Fixed::operator++()
{
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--()
{
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return temp;
}


Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
} 