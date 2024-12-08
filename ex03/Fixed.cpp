/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:04:42 by geonwkim          #+#    #+#             */
/*   Updated: 2024/12/08 23:06:47 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int intValue)
{
	_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed; // Use copy assignment operator
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	if (this != &fixed)
		this->_fixedPointValue = fixed.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& fixed) const
{
	return _fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed& fixed) const
{
	return _fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return _fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return _fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return _fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return _fixedPointValue != fixed.getRawBits();
}

// Converts fixed-point value to a floating-point number
float Fixed::toFloat(void) const
{
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

// Converts fixed-point value to an integer
int Fixed::toInt(void) const
{
	return _fixedPointValue >> _fractionalBits;
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits(_fixedPointValue + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits(_fixedPointValue - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits((_fixedPointValue * fixed.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed result;
	result.setRawBits((_fixedPointValue << _fractionalBits) / fixed.getRawBits());
	return result;
}

Fixed Fixed::operator++() // Pre-increment
{
	_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) // Post-increment
{
	Fixed temp = *this;
	_fixedPointValue++;
	return temp;
}

Fixed Fixed::operator--() // Pre-decrement
{
	_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) // Post-decrement
{
	Fixed temp = *this;
	_fixedPointValue--;
	return temp;
}

// Static member function
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}

// Gets	the raw fixed-point value
int Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

// Sets the raw fixed-point value
void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

// Overloaded insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
