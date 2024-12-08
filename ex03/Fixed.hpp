/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:04:39 by geonwkim          #+#    #+#             */
/*   Updated: 2024/12/08 23:06:45 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		int _fixedPointValue;	// To store the fixed-point number
		static const int _fractionalBits = 8; // The number of fractional bits
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed& operator=(const Fixed& fixed);

		// Comparison operators
		bool operator>(const Fixed& fixed) const;
		bool operator<(const Fixed& fixed) const;
		bool operator>=(const Fixed& fixed) const;
		bool operator<=(const Fixed& fixed) const;
		bool operator==(const Fixed& fixed) const;
		bool operator!=(const Fixed& fixed) const;

		Fixed operator+(const Fixed& fixed) const;
		Fixed operator-(const Fixed& fixed) const;
		Fixed operator*(const Fixed& fixed) const;
		Fixed operator/(const Fixed& fixed) const;

		Fixed operator++();	// Pre-increment
		Fixed operator++(int);	// Post-increment
		Fixed operator--();	// Pre-decrement
		Fixed operator--(int);	// Post-decrement

		// Member functions
		float toFloat(void) const;
		int toInt(void) const;		

		// Static member function
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		// Getters and Setters
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

// Overloaded insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
