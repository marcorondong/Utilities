/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:58:18 by marondon          #+#    #+#             */
/*   Updated: 2024/06/30 17:40:47 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

static void	testMandatory01(void)
{
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 01 :::::::::::::" << std::endl;
	std::cout << "::::: Test case provided by the subject :::::" << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void	testMandatory02(void)
{
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 02 :::::::::::::" << std::endl;
	std::cout << ":: Surpass learnMateria() and equip() limit :" << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

	IMateriaSource* src = new MateriaSource();
	if (src == NULL)
		return ;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice()); // This is extra so it won't learn it and will be "dangling".

	ICharacter* me = new Character("me");
	if (me == NULL)
	{
		delete src;
		return ;
	}

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp); // This is extra so it won't equip it and will be "dangling".

	ICharacter* bob = new Character("bob");
	if (bob == NULL)
	{
		delete src;
		delete me;
		return ;
	}

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}
/* 
void	testMandatory03(void)
{
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 03 :::::::::::::" << std::endl;
	std::cout << "::::::::::::: Testing Character :::::::::::::" << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	for (int i = 0; i < 6; i++) // Equipping all slots, and surpassing the idx.
		me->equip(new Ice);
	for (int i = 0; i < 6; i++) // Using all slots, and surpassing the idx.
		me->use(i, *bob);
	for (int i = 0; i < 6; i++) // Unequipping all slots, and surpassing the idx.
		me->unequip(i);
	for (int i = 0; i < 6; i++) // Trying to use an unexisting materia, and surpassing the idx.
		me->use(i, *bob);
	for (int i = 0; i < 6; i++) // Trying to unequip an unexisting materia, and surpassing the idx.
		me->unequip(i);

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("random"); // Cannot create it since type is unknown.
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob); // Cannot use it since it wasnt created.

	delete bob;
	delete me;
	delete src;
}

void	testMandatory03_bis(void)
{
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 03_bis :::::::::::::" << std::endl;
	std::cout << ": Testing Character Copy Constructor/Assignment :" << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

	ICharacter* bob = new Character("bob");

	Character* tinky = new Character("Tinky");
	std::cout << tinky->getName() << std::endl;

	tinky->equip(new Ice);
	tinky->use(0, *bob);

	Character* tinkyClone = new Character(*tinky);
	std::cout << tinkyClone->getName() << std::endl;

	tinky->unequip(0);
	tinkyClone->use(0, *bob);
	tinky->use(0, *bob);

	Character* winky = new Character("Winky");
	std::cout << winky->getName() << std::endl;

	Character* unknown = new Character;
	std::cout << unknown->getName() << std::endl;

	*unknown = *winky; // IMPORTANT! they are pointers, so I MUST DERREFERENCE them before using the Copy Assignment Operator.
	std::cout << unknown->getName() << std::endl;

	winky->use(0, *bob);
	unknown->use(0, *bob);

	winky->equip(new Cure);
	winky->use(0, *bob);
	unknown->use(0, *bob);

	Character* goku = new Character("Goku");
	std::cout << goku->getName() << std::endl;
	Character* freezer = new Character("Freezer");
	std::cout << freezer->getName() << std::endl;

	for (int i = 0; i < 6; i++) // Equipping all slots, and surpassing the idx.
		goku->equip(new Ice);
	for (int i = 0; i < 6; i++) // Using all slots, and surpassing the idx.
		goku->use(i, *freezer);

	for (int i = 0; i < 6; i++) // Using empty slots, and surpassing the idx.
		freezer->use(i, *goku);
	*goku = *freezer; // IMPORTANT! they are pointers, so I MUST DERREFERENCE them before using the Copy Assignment Operator.
	for (int i = 0; i < 6; i++) // Using all slots, and surpassing the idx.
		goku->use(i, *freezer);

	delete freezer;
	delete goku;
	delete unknown;
	delete winky;
	delete tinkyClone;
	delete tinky;
	delete bob;
}

void	testMandatory04(void)
{
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 04 :::::::::::::" << std::endl;
	std::cout << "::::::::::: Testing MateriaSource :::::::::::" << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

	IMateriaSource* src = new MateriaSource();
	
	for (int i = 0; i < 6; i++) // Trying to learn an unexisting materia, and surpassing the idx.
		src->learnMateria(NULL);

	for (int i = 0; i < 6; i++) // Surpassing the idx of LearnedMateria.
		src->learnMateria(new Ice());

	src->learnMateria(new Cure());  // Trying to learn a new materia with full LearnedMateria storage.

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure"); // Cannot create it since I could not learn it due to full LearnedMateria storege.
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob); // Cannot use it since I dont have it (Cure didn't get created).

	delete bob;
	delete me;
	delete src;
}

void	testMandatory04_bis(void)
{
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 04_bis :::::::::::::" << std::endl;
	std::cout << "Testing MateriaSource Copy Constructor/Assignment" << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

	MateriaSource* cartman = new MateriaSource();
	cartman->learnMateria(new Ice);
	cartman->createMateria("ice");

	MateriaSource* cartmanClone = new MateriaSource(*cartman);
	cartmanClone->createMateria("ice");

	cartman->learnMateria(new Cure);
	cartman->createMateria("cure");
	cartmanClone->createMateria("cure");

	MateriaSource* kenny = new MateriaSource();
	kenny->learnMateria(new Ice);
	kenny->createMateria("ice");

	MateriaSource* kennyCopy = new MateriaSource;
	kennyCopy->createMateria("ice");

	*kennyCopy = *kenny; // IMPORTANT! they are pointers, so I MUST DERREFERENCE them before using the Copy Assignment Operator.
	kennyCopy->createMateria("ice");
	
	kenny->learnMateria(new Cure);
	kenny->createMateria("cure");
	kennyCopy->createMateria("cure");

	MateriaSource* doraemon = new MateriaSource();
	MateriaSource* bulma = new MateriaSource();

	for (int i = 0; i < 6; i++) // Equipping all slots, and surpassing the idx.
		doraemon->learnMateria(new Ice);
	for (int i = 0; i < 6; i++) // Using all slots, and surpassing the idx.
		doraemon->createMateria("ice");

	for (int i = 0; i < 6; i++) // Using empty slots, and surpassing the idx.
		bulma->createMateria("ice");
	*doraemon = *bulma; // IMPORTANT! they are pointers, so I MUST DERREFERENCE them before using the Copy Assignment Operator.
	for (int i = 0; i < 6; i++) // Using all slots, and surpassing the idx.
		doraemon->createMateria("ice");

	delete bulma;
	delete doraemon;
	delete kennyCopy;
	delete kenny;
	delete cartmanClone;
	delete cartman;
}

void	testMandatory05(void)
{
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 05 :::::::::::::" << std::endl;
	std::cout << "::::::::: Testing invalid AMateria ::::::::::" << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(NULL);
	src->learnMateria(NULL);

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("random");
	me->equip(tmp);
	tmp = src->createMateria("stuff");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void	testMandatory06(void)
{
	std::cout << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
	std::cout << "::::::::::::: MANDATORY TEST 06 :::::::::::::" << std::endl;
	std::cout << ":::::::::::::: Testing AMateria :::::::::::::" << std::endl;
	std::cout << ":::::::::::::::::::::::::::::::::::::::::::::" << std::endl;

	AMateria* ice01 = new Ice();
	std::cout << ice01->getType() << std::endl;

	AMateria* ice02 = new Ice();
	std::cout << ice02->getType() << std::endl;

	AMateria* ice01Clone = ice01->clone();
	std::cout << ice01Clone->getType() << std::endl;

	*ice01 = *ice02; // IMPORTANT! they are pointers, so I MUST DERREFERENCE them before using the Copy Assignment Operator.

	Ice* trueIce = new Ice();
	std::cout << trueIce->getType() << std::endl;

	Ice* trueIceCopy = new Ice(*trueIce);
	std::cout << trueIceCopy->getType() << std::endl;

	*trueIceCopy = *trueIce; // IMPORTANT! they are pointers, so I MUST DERREFERENCE them before using the Copy Assignment Operator.

	delete ice01;
	delete ice02;
	delete ice01Clone;
	delete trueIce;
	delete trueIceCopy;
}
 */
int	main(void)
{
	testMandatory01(); // subject test case.
	testMandatory02(); // Surpassing learmateria and equip limit.
	// testMandatory03(); // Testing Character class.
	// testMandatory03_bis(); // Testing Character class Copy Constructor/Asigment.
	// testMandatory04(); // Testing MateriaSoruce class.
	// testMandatory04_bis(); // Testing MateriaSoruce class Copy Constructor/Asigment.
	// testMandatory05(); // Testing invalid materia.
	// testMandatory06(); // Testing AMateria class.
	return (0);
}
