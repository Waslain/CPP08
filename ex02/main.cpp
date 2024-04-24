/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:59:54 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/24 14:33:35 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

void	printVector(std::vector<int> & vector){

	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	ite = vector.end();

	std::cout << "vector: {";

	for (it = vector.begin(); it != ite; it++){
		
		if (it != vector.begin())
			std::cout << ", " << *it;
		else
			std::cout << *it;
		
	}
	std::cout << "}" << std::endl; 
}

int	main(void) {

	std::cout << "	-- SUBJECT TESTS --" << std::endl;

	/////////////////////////////
	//	WITH STACK

	std::cout << "WITH MUTANTSTACK :" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack.top() = " << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << "mstack.size() = " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	while (it != ite){
		std::cout << *it << "; ";
		++it;
	}

	std::cout << std::endl;

	std::stack<int> s(mstack);

	std::cout << std::endl;


	/////////////////////////////
	//	WITH LIST

	std::cout << "WITH LIST :" << std::endl;

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << "mstack.top() = " << list.back() << std::endl;
	
	list.pop_back();
	std::cout << "mstack.size() = " << list.size() << std::endl;
	
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	
	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();
	++lit;
	--lit;
	
	while (lit != lite){
		std::cout << *lit << "; ";
		++lit;
	}
	std::cout << std::endl;

	std::cout << std::endl;

	/* ************************************************************************** */

	std::cout << "	-- MY TESTS --" << std::endl;

	std::cout << "Insert mstack content into vector. . ." << std::endl;

	std::vector<int> vector;
	vector.insert(vector.end(), mstack.begin(), mstack.end());
	printVector(vector);

	
	
	return (0);
}