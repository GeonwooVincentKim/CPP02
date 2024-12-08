/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 23:04:34 by geonwkim          #+#    #+#             */
/*   Updated: 2024/12/08 23:13:39 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(2, 2);
    Point p2(10, 10);
    Point p3(0, 0);

    std::cout << "p1 is in triangle abc: " << bsp(a, b, c, p1) << std::endl;
    std::cout << "p2 is in triangle abc: " << bsp(a, b, c, p2) << std::endl;
    std::cout << "p3 is in triangle abc: " << bsp(a, b, c, p3) << std::endl;
    
    return 0;
}