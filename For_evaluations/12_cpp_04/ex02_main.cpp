/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:21:03 by marondon          #+#    #+#             */
/*   Updated: 2024/06/27 16:37:08 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <cstddef> // For NULL
#include <iostream> // For std::cout
#include <sstream> // For std::stringstream

#define NUM_ANIMALS 10
#define TOT_THOUGHTS 10
#define SPECIFIC_THOUGHT 4

static void	testMandatory01(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 01 :::::::::::::" << std::endl;

	AAnimal* animalArr[NUM_ANIMALS];
	for (int i = 0; i < NUM_ANIMALS; i++)
	{
		if (i < NUM_ANIMALS / 2)
            animalArr[i] = new Dog;
		else
            animalArr[i] = new Cat;
	}
	// Testing correct creation and type.
	for (int i = 0; i < NUM_ANIMALS; i++)
	{
		if (animalArr[i] != NULL)
		{
			std::cout << "animalArr[" << i << "] : ";
			animalArr[i]->makeSound();
		}
	}
	for (int i = 0; i < NUM_ANIMALS; i++)
		if (animalArr[i] != NULL)
			delete animalArr[i];
}

static void	testMandatory02(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 02 :::::::::::::" << std::endl;

	// Animal stackAnimal; // Error: Variable type 'Animal' is an abstract classclang(abstract_type_in_decl).
	// const Animal* meta = new Animal(); // Error: Allocating an object of abstract class type 'Animal'clang(allocation_of_abstract_type).
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j; // should not create a leak.
	delete i;
}

static void	testBrain(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: BRAIN TEST :::::::::::::" << std::endl;

	Brain* heapBrain = new Brain();
	Brain stackBrain;
	if (heapBrain != NULL)
	{
		for (int i = 0; i < TOT_THOUGHTS; i++)
		{
			std::stringstream buffer;
			buffer << "heapBrain is counting sheep number " << i;
			heapBrain->setIdea(i, buffer.str());
			buffer.clear();
			buffer.str(""); // This was more efficient (for old compilers): buffer.str(std::string());
			buffer << "stackBrain is counting star number " << i;
			stackBrain.setIdea(i, buffer.str());
		}
		std::cout << "one of heapBrain's ideas is: "
				<< heapBrain->getIdea(SPECIFIC_THOUGHT) << std::endl;
		std::cout  << "one of stackBrain's ideas is: "
				<< stackBrain.getIdea(SPECIFIC_THOUGHT) << std::endl;

		std::cout  << "all heapBrain's ideas are these : " << std::endl;
		heapBrain->printAllIdeas();
		std::cout  << "all stackBrain's ideas are these : " << std::endl;
		stackBrain.printAllIdeas();
	}
	delete heapBrain;
}

static void	testCat(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: CAT TEST :::::::::::::" << std::endl;

	Cat garfield;
	Cat impostor;

	garfield.think(0, "Lasagna!");
	garfield.think(1, "Jon");
	garfield.think(2, "Odie");
	garfield.think(3, "Sleep");
	garfield.think(4, "Watch TV");

	for (int i = 0; i < TOT_THOUGHTS; i++)
	{
		garfield.expressThoughts(1, i);
		impostor.expressThoughts(1, i);
	}

	impostor = garfield;

	for (int i = 0; i < TOT_THOUGHTS; i++)
	{
		garfield.expressThoughts(1, i);
		impostor.expressThoughts(1, i);
	}

	Cat garfieldClone(garfield);

	garfield.think(5, "Mooooooreee food!");
	garfield.think(6, "Pooky");
	garfield.think(7, "I'm bored");
	garfield.think(8, "Check the fridge for more food");
	garfield.think(9, "Watch more TV and fall asleep");
	impostor.think(5, "I don't know what the real one is thinking.. maybe in 'Mooooooreee food!'?");
	impostor.think(6, "I don't know what the real one is thinking.. maybe in 'Pooky'?");
	impostor.think(7, "I don't know what the real one is thinking.. maybe in 'I'm bored'?");
	impostor.think(8, "I don't know what the real one is thinking.. maybe in 'Check the fridge for more food'?");
	impostor.think(9, "I don't know what the real one is thinking.. maybe in 'Watch more TV and fall asleep'?");

	garfield.expressThoughts(0, 0);
	impostor.expressThoughts(0, 0);
	garfieldClone.expressThoughts(0, 0);
}

static void	testDog(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: DOG TEST :::::::::::::" << std::endl;

	Dog scoobyDoo;
	Dog impostor;

	scoobyDoo.think(0, "ScoobyCokies!");
	scoobyDoo.think(1, "Shaggy");
	scoobyDoo.think(2, "Ghost!");
	scoobyDoo.think(3, "Sleep");
	scoobyDoo.think(4, "Solve a mistery");

	for (int i = 0; i < TOT_THOUGHTS; i++)
	{
		scoobyDoo.expressThoughts(1, i);
		impostor.expressThoughts(1, i);
	}

	impostor = scoobyDoo;

	for (int i = 0; i < TOT_THOUGHTS; i++)
	{
		scoobyDoo.expressThoughts(1, i);
		impostor.expressThoughts(1, i);
	}

	Dog scoobyDooClone(scoobyDoo);

	scoobyDoo.think(5, "Mooooooreee ScoobyCokies!");
	scoobyDoo.think(6, "Daphne");
	scoobyDoo.think(7, "ScrappyDoo!");
	scoobyDoo.think(8, "Bite my tail");
	scoobyDoo.think(9, "Travel in the mistery machine!");
	impostor.think(5, "I don't know what the real one is thinking.. maybe in 'Mooooooreee ScoobyCokies!'?");
	impostor.think(6, "I don't know what the real one is thinking.. maybe in 'Daphne'?");
	impostor.think(7, "I don't know what the real one is thinking.. maybe in 'ScrappyDoo!'?");
	impostor.think(8, "I don't know what the real one is thinking.. maybe in 'Bite my tail'?");
	impostor.think(9, "I don't know what the real one is thinking.. maybe in 'Travel in the mistery machine!'?");

	scoobyDoo.expressThoughts(0, 0);
	impostor.expressThoughts(0, 0);
	scoobyDooClone.expressThoughts(0, 0);
}

int	main(void)
{
	testMandatory01();
	testMandatory02();
	testBrain();
	testCat();
	testDog();
	return (0);
}
