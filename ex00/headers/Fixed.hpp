/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:47:40 by praclet           #+#    #+#             */
/*   Updated: 2021/03/22 12:56:01 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
		static int const fracBitsNb = 8;
		int _value;
	public:
		Fixed();
		Fixed(Fixed const & src);
		~Fixed();
		Fixed & operator = (Fixed const & src);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
