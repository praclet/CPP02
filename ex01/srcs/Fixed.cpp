/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:55:32 by praclet           #+#    #+#             */
/*   Updated: 2021/03/23 14:08:08 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << fracBitsNb;
}

Fixed::Fixed(float const value)
{
	float	tmp;

	std::cout << "Float constructor called" << std::endl;
	tmp = 1;
	for (int i = 0;i < fracBitsNb;i++)
		tmp *= 2;
	_value = value * tmp;
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
	float	tmp;

	tmp = 1;
	for (int i = 0;i < fracBitsNb;i++)
		tmp *= 2;
	return ((float) _value / tmp);
}

std::ostream & operator << (std::ostream & os, Fixed const & f)
{
	os << f.toFloat();
	return (os);
}
