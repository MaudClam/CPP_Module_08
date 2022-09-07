/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:59:33 by mclam             #+#    #+#             */
/*   Updated: 2022/09/06 19:59:33 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define VOLUME 		100000
# define VOLUME1 		10000000
# define VOLUME2 		10000000
# define OUTPUT_LIMIT	3

# include <iostream>
# include <list>
# include <limits>
# include <string>
# include <algorithm>

class Span
{
private:
	unsigned int	_N;
	std::list<int>	_span;
					// Canonical
					Span( void );
public:
					// Canonical
					Span( const Span &span );
	Span			&operator=( const Span &span );
					~Span( void );
	
					Span( const unsigned int N );
	void			addNumber( const int &x );
	void			addRAnge( int *first, int *last );
	int				shortestSpan( void );
	int				longestSpan( void );
	void			display( std::ostream &out );
};

std::ostream	&operator<<( std::ostream &out, Span &span );

#endif
