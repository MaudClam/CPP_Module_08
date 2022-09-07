/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:38:18 by mclam             #+#    #+#             */
/*   Updated: 2022/09/07 16:38:18 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
#include <vector>
#include <deque>
#include <list>

template< typename T, class Container > class MutantStack : public std::stack< T, Container >
{
private:
	
public:
	// Canonical
				MutantStack( void ) {};
				MutantStack( const MutantStack &mstack ) { *this = mstack; };
				~MutantStack( void ) {};
	MutantStack	&operator=( const MutantStack &mstack ) {
		if (this != mstack) { this->c = mstack.c; } return *this; };
	
	typedef typename std::stack<T, Container>::container_type	container_type;
	typedef typename container_type::iterator					iterator;
	typedef typename container_type::const_iterator				const_iterator;
	typedef typename container_type::reverse_iterator			reverse_iterator;
	typedef typename container_type::const_reverse_iterator		const_reverse_iterator;
	
	iterator				begin( void ) { return this->c.begin(); };
	iterator				end( void ) { return this->c.end(); };

	const_iterator			begin( void ) const { return this->c.begin(); };
	const_iterator			end( void ) const { return this->c.end(); };

	reverse_iterator		rbegin( void ) { return this->c.rbegin(); };
	reverse_iterator		rend( void ) { return this->c.rend(); };

	const_reverse_iterator	rbegin( void ) const { return this->c.rbegin(); };
	const_reverse_iterator	rend( void ) const { return this->c.rend(); };
};

#endif
