/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:59:18 by mclam             #+#    #+#             */
/*   Updated: 2022/09/06 19:59:18 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _N( 0 ), _span( 0 ) {};

Span::Span( const Span &span ) { *this = span; };

Span	&Span::operator=(const Span &span) {
	if ( this != &span ) {
		this->_span.clear();
		this->_N = span._N;
		this->_span = span._span;
	}
	return *this;
}

Span::~Span( void ) { _span.clear(); }

Span::Span( const unsigned int N ) : _N( N ) {}

void	Span::addNumber( const int &x ) {
	if ( _span.size() >= _N ) {
		throw std::out_of_range("can't add element, storge is full");
	}
	_span.push_back( x );
}

void	Span::addRAnge( int *first, int *last ) {
	if ( _span.size() + ( last - first ) / sizeof(int) > _N ) {
		throw std::out_of_range("can't add range, will overflow");
	}
	_span.insert(_span.end(), first, last);
}

int	Span::shortestSpan( void ) {
	std::list<int>::iterator	it, it1;
	int							min = std::numeric_limits<int>::max();
	
	if ( _span.size() < 2 ) {
		throw std::out_of_range("impossible, number of elements is less than 2");
	}
	else if ( _span.size() == 2 ) {
		min  =	std::max( *_span.begin(), *_span.end() ) -
				std::min( *_span.begin(), *_span.end() );
	}
	else {
		std::list<int>	clone = _span;

		it = it1 = clone.begin();
		clone.sort();
		for ( ++it1; it1 != clone.end(); ++it1, ++it ) {
			min = std::min(min, *it1 - *it);
		}
	}
	return min;
}

int	Span::longestSpan( void ) {
	int	max = 0;
	
	if ( _span.size() < 2 ) {
		throw std::out_of_range("impossible, number of elements is less than 2");
	}
	else if ( _span.size() == 2 ) {
		max  =	std::max( *_span.begin(), *_span.end() ) -
				std::min( *_span.begin(), *_span.end() );
	}
	else {
		max  =	*std::max_element( _span.begin(), _span.end() ) -
				*std::min_element( _span.begin(), _span.end() );
	}
	return max;
}

void	Span::display( std::ostream &out )
{
	size_t	oSize = _span.size();
	
	if ( _span.begin() != _span.end() )
	{
		std::list<int>::iterator	it = _span.begin();

		out << "[" << oSize << "]: { ";
		if ( oSize - 1 > OUTPUT_LIMIT ) {
			for ( oSize = OUTPUT_LIMIT; oSize--; ++it ) { std::cout << *it << ", "; }
			std::cout	<< "..., ";
		}
		else {
			for ( oSize -= 1; oSize--; ++it ) { std::cout << *it << ", "; }
		}
		it = _span.end();
		out << *(--it);
		out << " }" << std::endl;
	}
	else {
		out << "[" << oSize << "]: {";
		out << "}" << std::endl;
	}
}

std::ostream	&operator<<( std::ostream &out, Span &span ) {
	span.display( out );
	return out;
}
