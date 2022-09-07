/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:59:08 by mclam             #+#    #+#             */
/*   Updated: 2022/09/06 19:59:08 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(int, const char**) {
	{
		std::cout << "\n=====Subject Test=====" << std::endl;
		
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	{
		std::cout << "\n====ExceptionsTest====" << std::endl;
		
		Span sp = Span(1);
		
		std::cout << "sp" << sp;
		
		try { sp.addNumber(6); std::cout << "1 element '6' added" << std::endl; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "sp" << sp;

		try { sp.addNumber(3); std::cout << "2 element '3' added" << std::endl; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "sp" << sp;

		try { std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }

		try { std::cout << "Longest Span: " << sp.longestSpan() << std::endl; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }
	}
	
	{
		std::cout << "\n===High Volume Tests==" << std::endl;
		Span	sp(VOLUME);
		
		std::cout << "sp" << sp;

		int		tmp[VOLUME];

		for ( int i = 0; i < VOLUME; i++ ) { tmp[i] = std::rand(); }
				
		try { sp.addRAnge(tmp, tmp + VOLUME);; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "sp" << sp;
		
		try { std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }

		try { std::cout << "Longest Span: " << sp.longestSpan() << std::endl; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }

		try { sp.addRAnge(tmp, tmp + VOLUME);; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }
	}
	
	{
		std::cout << "\n====Test With new=====" << std::endl;
		int	*tmp = new int[VOLUME1];
		Span	sp(VOLUME1);
		
		for ( int i = 0; i < VOLUME1; i++ ) { tmp[i] = std::rand(); }
		
		std::cout << "sp" << sp;
		
		try { sp.addRAnge(tmp, tmp + VOLUME1);; }
		catch (std::exception &e) { std::cerr << e.what() << std::endl; }

		std::cout << "sp" << sp;

		delete [] tmp;
	}
	
	{
		std::cout << "\n===Test addNumber()====" << std::endl;
		Span	sp(VOLUME2);
		
		for ( int i = 0; i < VOLUME2; i++ ) {
			try {
				sp.addNumber( std::rand() );
			}
			catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
				break ;
			}
		}
				
		std::cout << "sp" << sp;
	}
	
	std::cout << std::endl;
	return 0;
}
