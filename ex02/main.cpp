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
	{
		std::cout << "\n############## SUBJECT STACK TEST, A LITTLE EXTENDED\n";

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
	}
	
	{
		std::cout << "\n\n############## TEST WHITH ONLY LIST CONTAINER\n";

		std::list<int>	jastList;

		jastList.push_back(5);
		jastList.push_back(17);

		std::cout << jastList.back() << std::endl;

		jastList.pop_back();

		std::cout << jastList.size() << std::endl;

		jastList.push_back(3);
		jastList.push_back(5);
		jastList.push_back(737);
		//[...]
		jastList.push_back(0);

		std::list<int>::iterator it = jastList.begin();
		std::list<int>::iterator ite = jastList.end();

		std::list<int>::reverse_iterator rit = jastList.rbegin();
		std::list<int>::reverse_iterator rite = jastList.rend();

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
	}
	return 0;
}
