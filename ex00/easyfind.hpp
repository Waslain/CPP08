/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:29:57 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/19 18:35:12 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

template <typename T>
typename T::iterator easyfind (T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::out_of_range("Value not found in container");
	return (it);
}