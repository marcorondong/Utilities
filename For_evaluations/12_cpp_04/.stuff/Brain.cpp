/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:02:47 by marondon          #+#    #+#             */
/*   Updated: 2024/06/27 15:00:28 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream> // For std::cout
#include <sstream> // For std::stringstream

void	Brain::setIdea(int index, std::string idea)
{
	int i = index % 100;
	std::stringstream buffer;
	buffer << "Mental list[" << i << "] = " << idea;
	ideas[i] = buffer.str();
}

const std::string&	Brain::getIdea(int index) const
{
	int i = index % 100;
	return (ideas[i]);
}

void	Brain::printAllIdeas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << ideas[i] << std::endl;
}

/* ===================== Orthodox Canonical Form parts:==================== */
// Default Constructor.
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		setIdea(i, "...");
	std::cout << "Brain Default Constructor called"<< std::endl;
}

// Default Destructor.
Brain::~Brain()
{
	std::cout << "Brain Default Destructor called"<< std::endl;
}

// Copy Constructor.
Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain Copy Constructor called" << std::endl;
}

// Copy Assigment Operator.
Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
		std::cout << "Brain Copy Assigment Operator called" << std::endl;
	}
	return (*this);
}

//============================================================================
// Note the following:
// 1) In setIdea():
// I Need to receive idea as a normal string (and not reference)
// so I can copy string literals in for/while loops.
// 
// 2) In getIdea():
// If I want to modify the idea, I do this: std::string = getIdea(index);
// and this creates a copy of the idea which I can modify.