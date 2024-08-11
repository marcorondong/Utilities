/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:05:26 by marondon          #+#    #+#             */
/*   Updated: 2024/06/27 16:30:54 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AAnimal.hpp"
#include <iostream> // For std::cout

void	Dog::makeSound() const
{
	std::cout << getType() << ": " << DOG_SOUND << std::endl;
}

void	Dog::think(int index, const std::string& idea)
{
	if (_brain != NULL)
		_brain->setIdea(index, idea);
}

void	Dog::expressThoughts(int mode, int index) const
{
	std::cout << getType() << ": ";
	if (_brain == NULL)
	{
		std::cout << "has NULL brain" << std::endl;
		return ;
	}
	if (mode == 1)
		std::cout << _brain->getIdea(index % 100) << std::endl;
	else
	{
		std::cout << std::endl;
	 	_brain->printAllIdeas();
	}
}

/* ===================== Orthodox Canonical Form parts:==================== */
// Default Constructor.
Dog::Dog() : AAnimal(), _brain(new Brain)
{
	if (_brain == NULL)
		std::cout << "Brain creation failed"<< std::endl;
	type = DOG_TYPE;
	std::cout << "Dog Default Constructor called"<< std::endl;
}

// Default Destructor
Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Default Destructor called"<< std::endl;
}

// Remember that _brain is a pointer, so I need to derreference it
// to access its values and be able to use the Copy Constructor of Brain Class.
// Copy Constructor.
Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain))
{
	if (_brain == NULL)
		std::cout << "Brain creation failed"<< std::endl;
	type = other.type;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

// Remember that _brain is a pointer, so I need to derreference it
// to access its values and be able to use the Copy Assigment Operator of Brain Class.
// Copy Assigment Operator.
Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other); // Call base class assignment operator.
		if (_brain && other._brain)
			*_brain = *other._brain;
		type = other.type;;
		std::cout << "Dog Copy Assigment Operator called" << std::endl;
	}
	return (*this);
}

//============================================================================
// Note the following:
// 1) Since I dont have a type attribute inside Dog Class because Im inheriting it
// from AAnimal; then I cannot use it in the initialization list. I have to use it
// inside the constructor body.