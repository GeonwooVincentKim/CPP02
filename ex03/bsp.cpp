/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:06:39 by geonwkim          #+#    #+#             */
/*   Updated: 2024/12/08 23:12:39 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Helper function to calculate the area of a triangle
static Fixed area(Point const &p1, Point const &p2, Point const &p3) {
    // Area formula: |(x1(y2-y3) + x2(y3-y1) + x3(y1-y2)) / 2|
    return Fixed(
        (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
         p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
         p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) /
        2).toFloat();
}

// BSP function to check if the point lies inside the triangle
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c).toFloat();

    // Sub-triangle areas
    Fixed areaPAB = area(point, a, b).toFloat();
    Fixed areaPBC = area(point, b, c).toFloat();
    Fixed areaPCA = area(point, c, a).toFloat();

    // Check if point is inside the triangle
    return (areaPAB + areaPBC + areaPCA == totalArea) &&
           (areaPAB > 0 && areaPBC > 0 && areaPCA > 0);
}
