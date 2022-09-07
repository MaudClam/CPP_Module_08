/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:53:01 by mclam             #+#    #+#             */
/*   Updated: 2022/09/05 15:53:01 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <deque>
#include <list>

// Not for c++98
//#include <forward_list>
//#include <array>

#include "easyfind.tpp"
#include "easyfind.hpp"

// Not for c++98
//std::array<int, MAX_N>		fillArrayContainer( const int *i );

int main(int, const char**)
{
	int	i[] = { 2, 4, 8, 1000000, 0, -1, std::numeric_limits<int>::min() };
	int	numToFind = -1;
	int	wrongNumToFind = 3;

	std::vector<int>		v( i, i + MAX_N );
	std::deque<int>			d( i, i + MAX_N );
	std::list<int>			l( i, i + MAX_N );

	display("\nstd::vector<int> v", v);
	findAndDisplay(v, numToFind);
	findAndDisplay(v, wrongNumToFind);
	
	display("\nstd::deque<int> d", d);
	findAndDisplay(d, numToFind);
	findAndDisplay(d, wrongNumToFind);

	display("\nstd::list<int> l", l);
	findAndDisplay(l, numToFind);
	findAndDisplay(l, wrongNumToFind);

// Not for c++98
//	std::forward_list<int>	f( i, i + MAX_N );
//	std::array<int, MAX_N>	a = fillArrayContainer( i );
//
//	display("\nstd::array<int> a", a);
//	findAndDisplay(a, numToFind);
//	findAndDisplay(a, wrongNumToFind);
//
//	display("\nstd::forward_list<int> f", f);
//	findAndDisplay(f, numToFind);
//	findAndDisplay(f, wrongNumToFind);

	return 0;
}

// Not for c++98
//std::array<int, MAX_N>	fillArrayContainer( const int *i )
//{
//	std::array<int, MAX_N>				a;
//	std::array<int, MAX_N>::iterator	it = a.begin();
//
//	for ( int j = 0; j < MAX_N; ++it ) {
//		*it = i[j++];
//	}
//	return a;
//}

// This function is needed for std::count_if()
bool	returnTrue( int ) {
	return true;
}
