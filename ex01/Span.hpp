/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:19:16 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/22 18:36:57 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();
		
		Span &operator=(const Span &src);

		void addNumber(int n);
		void addNumbers(int n[], unsigned int size);
		void addNumbers(std::vector<int> n);
		int shortestSpan();
		int longestSpan();

		size_t getSize() const;
		std::vector<int> getNumbers() const;

		void toPrint(const std::string & name) const;
	private:
		Span();
		unsigned int _maxSize;
		std::vector<int> _numbers;
};