/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:04:54 by geonwkim          #+#    #+#             */
/*   Updated: 2024/12/08 23:12:12 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& point);
		~Point();

		Point& operator=(const Point& point);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
