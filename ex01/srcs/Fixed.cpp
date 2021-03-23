/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:55:32 by praclet           #+#    #+#             */
/*   Updated: 2021/03/23 16:19:52 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) : _value(src._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value << fracBitsNb)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value((int)roundf(value * (1 << fracBitsNb)))
{
}

Fixed & Fixed::operator = (Fixed const & src)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = src._value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int Fixed::toInt(void) const
{
	return (_value >> fracBitsNb);
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << fracBitsNb));
}

std::ostream & operator << (std::ostream & os, Fixed const & f)
{
	os << f.toFloat();
	return (os);
}
