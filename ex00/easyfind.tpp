/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:40:00 by mclam             #+#    #+#             */
/*   Updated: 2022/09/06 15:40:00 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// THE FILE CONTAINS TEMPLATE FUNCTIONS FOR TESTS

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

# define MAX_N			7
# define OUTPUT_LIMIT	10

bool										returnTrue( int );
template<typename T> typename T::iterator	LastElementIterator( T &a );

template<typename T> void	display( const char *prompt, T &a )
{
	size_t	oSize = std::count_if( a.begin(), a.end(), returnTrue );
	
	if ( a.begin() != a.end() )
	{
		typename T::iterator	it = a.begin();

		std::cout << prompt << "[" << oSize << "]: { ";
		if ( oSize - 1 > OUTPUT_LIMIT ) {
			for ( oSize = OUTPUT_LIMIT; oSize--; ++it ) { std::cout << *it << ", "; }
			std::cout	<< "..., ";
		}
		else {
			for ( oSize -= 1; oSize--; ++it ) { std::cout << *it << ", "; }
		}
		std::cout << * LastElementIterator( a );
		std::cout << " }" << std::endl;
	}
	else {
		std::cout << prompt << "[" << oSize << "]: {";
		std::cout << "}" << std::endl;
	}
}

template<typename T> void	findAndDisplay( T &a, int n )
{
	typename T::iterator	it;

	std::cout << "Finding: " << n << ", ";
	try {
		it = easyfind(a, n);
		std::cout << "found: " << *it << std::endl; }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl; }
}

// This function is needed for containers like forward_list
// that do not have a decrement operator
template<typename T> typename T::iterator	LastElementIterator( T &a )
{
	typename T::iterator	it = a.begin();

	if ( it != a.end() )
		for ( typename T::iterator tmp = it; tmp != a.end(); ++tmp ) { it = tmp; }
	return it;
}

#endif
