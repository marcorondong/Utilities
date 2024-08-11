/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:21:03 by marondon          #+#    #+#             */
/*   Updated: 2024/06/24 15:14:02 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <cstddef>
#include <iostream>

static void	testMandatory01(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 01 :::::::::::::" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	if (meta != NULL && j != NULL && i != NULL)
	{
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
	}
	delete meta;
	delete j;
	delete i;
}

static void	testMandatory02(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 02 :::::::::::::" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	if (meta2 != NULL && j != NULL && i != NULL)
	{
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the WrongAnimal sound!
		j->makeSound();
		meta2->makeSound();
	}
	delete meta2;
	delete j;
	delete i;
}

static void	testAnimal(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: ANIMAL TEST :::::::::::::" << std::endl;
	const Animal* heapAnimal = new Animal();
	Animal stackAnimal;
	if (heapAnimal != NULL)
	{
		std::cout << heapAnimal->getType() << " " << std::endl;
		std::cout << stackAnimal.getType() << " " << std::endl;
		heapAnimal->makeSound();
		stackAnimal.makeSound();
	}
	delete heapAnimal;
}

static void	testCat(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: CAT TEST :::::::::::::" << std::endl;
	const Cat* HeapCat = new Cat();
	Cat stackCat;
	Animal* animalPtrCat = new Cat();
	if (HeapCat != NULL && animalPtrCat != NULL)
	{
		std::cout << HeapCat->getType() << " " << std::endl;
		std::cout << stackCat.getType() << " " << std::endl;
		std::cout << animalPtrCat->getType() << " " << std::endl;
		HeapCat->makeSound();
		stackCat.makeSound();
		animalPtrCat->makeSound();
	}
	delete HeapCat;
	delete animalPtrCat;
}

static void	testDog(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: DOG TEST :::::::::::::" << std::endl;
	const Dog* HeapDog = new Dog();
	Dog stackDog;
	Animal* animalPtrDog = new Dog();
	if (HeapDog != NULL && animalPtrDog != NULL)
	{
		std::cout << HeapDog->getType() << " " << std::endl;
		std::cout << stackDog.getType() << " " << std::endl;
		std::cout << animalPtrDog->getType() << " " << std::endl;
		HeapDog->makeSound();
		stackDog.makeSound();
		animalPtrDog->makeSound();
	}
	delete HeapDog;
	delete animalPtrDog;
}

static void	testWrongAnimal(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: WRONGANIMAL TEST :::::::::::::" << std::endl;
	const WrongAnimal* heapWrongAnimal = new WrongAnimal();
	if (heapWrongAnimal != NULL)
	{
		WrongAnimal stackWrongAnimal;
		std::cout << heapWrongAnimal->getType() << " " << std::endl;
		std::cout << stackWrongAnimal.getType() << " " << std::endl;
		heapWrongAnimal->makeSound();
		stackWrongAnimal.makeSound();
	}
	delete heapWrongAnimal;
}

static void	testWrongCat(void)
{
	std::cout << std::endl;
	std::cout << "::::::::::::: WRONGCAT TEST :::::::::::::" << std::endl;
	const WrongCat* HeapWrongCat = new WrongCat();
	WrongCat stackWrongCat;
	WrongAnimal* wrongAnimalPtrWrongCat = new WrongCat();
	if (HeapWrongCat != NULL && wrongAnimalPtrWrongCat != NULL)
	{
		std::cout << HeapWrongCat->getType() << " " << std::endl;
		std::cout << stackWrongCat.getType() << " " << std::endl;
		std::cout << wrongAnimalPtrWrongCat->getType() << " " << std::endl;
		HeapWrongCat->makeSound();
		stackWrongCat.makeSound();
		wrongAnimalPtrWrongCat->makeSound();
	}
	delete HeapWrongCat;
	delete wrongAnimalPtrWrongCat;
}

int	main(void)
{
	testMandatory01();
	testMandatory02();
	testAnimal();
	testCat();
	testDog();
	testWrongAnimal();
	testWrongCat();
	return (0);
}
