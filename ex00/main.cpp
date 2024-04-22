/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:20:22 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/19 19:20:25 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

template <typename T>
void print(const T& value)
{
	std::cout << value << " ";
}

int main( void )
{
	std::vector<int> vect;
	vect.push_back(2);
	vect.push_back(16);
	vect.push_back(77);
	vect.push_back(34);
	vect.push_back(50);
	std::cout << "vect -> ";
	for_each(vect.begin(), vect.end(), print<int>);
	std::cout << std::endl << std::endl;

	std::cout << "easyfind(vect, 77) -> ";
	try
	{
		std::cout << *easyfind(vect, 77) << " found in the vector." << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Out of range exception: " << e.what() << "." << std::endl;
	}

	std::cout << "easyfind(vect, 42) -> ";
	try
	{
		std::cout << *easyfind(vect, 42) << " found in the vector." << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Out of range exception: " << e.what() << "." << std::endl;
	}
	return 0;
}