/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:33:04 by mclam             #+#    #+#             */
/*   Updated: 2022/09/07 16:33:04 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

#define CONTAINER vector
//#define CONTAINER deque
//#define CONTAINER list

int main(int, const char**) {
	MutantStack< int, std::CONTAINER<int> > mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack< int, std::CONTAINER<int> >::iterator it = mstack.begin();
	MutantStack< int, std::CONTAINER<int> >::iterator ite = mstack.end();

	MutantStack< int, std::CONTAINER<int> >::reverse_iterator rit = mstack.rbegin();
	MutantStack< int, std::CONTAINER<int> >::reverse_iterator rite = mstack.rend();

	std::cout << "\n====Test Inerators======\n";
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n====Reverce Inerators===\n";
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	
	std::stack<int, std::CONTAINER<int> > s(mstack);

	return 0;
}
