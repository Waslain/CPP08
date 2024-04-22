/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:19:20 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/22 18:37:25 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	//std::cout << "Default Span constructor called" << std::endl;
}

Span::Span(unsigned int n) : _maxSize(n)
{
	//std::cout << "Span parametric constructor called" << std::endl;
}

Span::Span(const Span &copy) : _maxSize(copy._maxSize), _numbers(copy._numbers)
{
	//std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span()
{
	//std::cout << "Span deconstructor called" << std::endl;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_maxSize = src._maxSize;
		_numbers = src._numbers;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (n > INT_MAX || n < INT_MIN)
		throw std::out_of_range("Number is out of range");
	if (_numbers.size() >= _maxSize)
		throw std::length_error("Span is full");
	_numbers.push_back(static_cast<int>(n));
}

void Span::addNumbers(int n[], unsigned int size)
{
	if (getSize() + size > _maxSize)
		throw std::length_error("Span would be/is already full");
	_numbers.insert(_numbers.end(), n, n + size);
}

void Span::addNumbers(std::vector<int> n)
{
	if (n.size() > (_maxSize - getSize()))
		throw std::length_error("Span would be/is already full");
	_numbers.insert(_numbers.end(), n.begin(), n.end());
}

int Span::longestSpan()
{
	if (_numbers.size() <= 1)
		throw std::length_error("Span is too short");
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	return (*maxIt - *minIt);
}

int Span::shortestSpan()
{
	if (_numbers.size() <= 1)
		throw std::length_error("Span is too short");
	
	std::vector<int> sortedNum = _numbers;
	std::sort(sortedNum.begin(), sortedNum.end());

	int shortestSpan = sortedNum[1] - sortedNum[0];
	for (size_t i = 2; i < sortedNum.size(); i++)
	{
		shortestSpan = std::min(shortestSpan, sortedNum[i] - sortedNum[i - 1]);
	}

	return shortestSpan;
}

size_t Span::getSize() const
{
	return _numbers.size();
}

std::vector<int> Span::getNumbers() const
{
	return _numbers;
}

void	Span::toPrint(const std::string & name) const {
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = _numbers.end();

	for (it = _numbers.begin(); it != ite; it++)
	{
		if (it == _numbers.begin())
			std::cout << name << ": {" << *it;
		else
			std::cout << ", " << *it;
	}
	std::cout << "}" << std::endl;
}