/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:47:40 by praclet           #+#    #+#             */
/*   Updated: 2021/03/23 14:07:34 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
		static int const fracBitsNb = 8;
		int _value;
	public:
		Fixed();
		Fixed(Fixed const & src);
		Fixed(int const i);
		Fixed(float const f);
		~Fixed();
		Fixed & operator = (Fixed const & src);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;
};

std::ostream & operator << (std::ostream & os, Fixed const & f);

#endif
