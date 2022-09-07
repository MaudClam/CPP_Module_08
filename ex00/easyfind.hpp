/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:53:15 by mclam             #+#    #+#             */
/*   Updated: 2022/09/05 15:53:15 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T> typename T::iterator	easyfind( T &a, int n )
{
	if ( a.begin() != a.end() )
	{
		typename T::iterator	it = std::find( a.begin(), a.end(), n );
		
		if ( it != a.end() )
			return it;
	}
	throw std::out_of_range("not found");
}

#endif
