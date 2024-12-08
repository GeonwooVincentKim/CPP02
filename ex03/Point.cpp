/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:06:00 by geonwkim          #+#    #+#             */
/*   Updated: 2024/12/08 23:09:36 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y) {}

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point::~Point() {}

Point& Point::operator=(const Point& point)
{
	(void)point;
	return *this;
}

Fixed Point::getX(void) const
{
	return x;
}

Fixed Point::getY(void) const
{
	return y;
}
