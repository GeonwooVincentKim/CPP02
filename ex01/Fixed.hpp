/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:46:00 by geonwkim          #+#    #+#             */
/*   Updated: 2024/12/08 22:34:45 by geonwkim         ###   ########.fr       */
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

		// Member functions
		float toFloat(void) const;
		int toInt(void) const;		

		// Getters and Setters
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

// Overloaded insertion (<<) operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
