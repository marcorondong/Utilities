/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:17:58 by marondon          #+#    #+#             */
/*   Updated: 2024/07/24 15:54:26 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <iostream>
#include <sstream>

#define FILLCHAR1 '=' // For printing the Separator.
#define FILLCHAR2 ':' // For printing the Separator.
#define AMOUNT 5

static void	printFillChar(char fillChar, int count, bool newline)
{
	for (int i = 0; i < count; i++)
		std::cout << fillChar;
	if (newline)
		std::cout << std::endl;
}

static void	ft_printSeparator(const std::string& header, bool isHeader)
{
	size_t len = header.length();
	const int width = 80;
	if (len > width)
	{
		if (isHeader)
			printFillChar(FILLCHAR1, len, true);
		std::cout << header << std::endl;
		if (isHeader)
			printFillChar(FILLCHAR1, len, true);
	}
	else
	{
		int padding = (width - len) / 2;
		if (isHeader)
			printFillChar(FILLCHAR1, width, true);
		printFillChar(FILLCHAR2, padding, false);
		std::cout << header;
		printFillChar(FILLCHAR2, padding + (width - len) % 2, false); // Handle odd padding.
		std::cout << std::endl;
		if (isHeader)
			printFillChar(FILLCHAR1, width, true);
	}
}

static void	testingInt(void)
{
	std::cout << std::endl;
	ft_printSeparator("Testing Array class with ints", true);

	std::cout << "Checking what's printed when new int(): ";
	int * a = new int();
	std::cout << *a << std::endl;
	delete a;
	std::cout << std::endl;

	Array <int> normalArrFive(AMOUNT);
	for (int i = 0; i < AMOUNT; i++)
		normalArrFive[i] = i;
	std::cout << "normalArrFive: ";
	normalArrFive.ft_printArrElement();

	Array <int> emptyArrTen(AMOUNT + 5);
	std::cout << "emptyArrTen: ";
	emptyArrTen.ft_printArrElement();

	std::cout << std::endl;
	ft_printSeparator("Testing Copy assigment operator (emptyArrTen = normalArrFive)", false);
	emptyArrTen = normalArrFive;
	std::cout << "emptyArrTen: ";
	emptyArrTen.ft_printArrElement();
	std::cout << "Modifying emptyArrTen" << std::endl;
	for (int i = 0; i < AMOUNT; i++)
		emptyArrTen[i] = i + AMOUNT;
	std::cout << "emptyArrTen: ";
	emptyArrTen.ft_printArrElement();
	std::cout << "normalArrFive: ";
	normalArrFive.ft_printArrElement();

	std::cout << std::endl;
	ft_printSeparator("Testing constant Array)", false);
	const Array <int> constArr(AMOUNT);
	for (int i = 0; i < AMOUNT; i++)
		std::cout << constArr[i] << (i < AMOUNT - 1 ? " " : "");
	std::cout << std::endl;

	std::cout << std::endl;
	ft_printSeparator("Testing exceptions (accesing invalid index)", false);
	try
	{
		unsigned int idx = normalArrFive.size();
		std::cout << "normalArrFive[" << (idx - 1) << "]" << normalArrFive[idx - 1] << std::endl;
		std::cout << "normalArrFive[" << (idx) << "]" << normalArrFive[idx] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//==================================
	std::cout << std::endl;
	ft_printSeparator("My test", false);
	Array<int> emptyArr;
	emptyArr.ft_printArrElement();
	Array<int> arr3(3);
	for (int i = 0; i < 3; i++)
		arr3[i] = i;
	arr3.ft_printArrElement();
	// emptyArr = arr3;
	// emptyArr.ft_printArrElement();
	arr3 = emptyArr;
	arr3.ft_printArrElement();
	//==================================

	return ;
}

static void	testingString(void)
{
	std::cout << std::endl;
	ft_printSeparator("Testing Array class with strings", true);

	Array<std::string> nomalWordsArr(AMOUNT);
	for (int i = 0; i < AMOUNT; i++)
	{
		std::stringstream ss;
		ss << "Mystr_N_" << i;
		nomalWordsArr[i] = ss.str();
	}
	std::cout << "nomalWordsArr: ";
	nomalWordsArr.ft_printArrElement();

	Array <std::string> emptyArrTen(AMOUNT + 5);
	std::cout << "emptyArrTen: ";
	emptyArrTen.ft_printArrElement();

	std::cout << std::endl;
	ft_printSeparator("Testing Copy assigment operator (emptyArrTen = nomalWordsArr)", false);
	emptyArrTen = nomalWordsArr;
	std::cout << "emptyArrTen: ";
	emptyArrTen.ft_printArrElement();
	std::cout << "Modifying emptyArrTen" << std::endl;
	for (int i = 0; i < AMOUNT; i++)
	{
		std::stringstream ss;
		ss << "New_string_N_" << (i + AMOUNT);
		emptyArrTen[i] = ss.str();
	}
	std::cout << "emptyArrTen: ";
	emptyArrTen.ft_printArrElement();
	std::cout << "nomalWordsArr: ";
	nomalWordsArr.ft_printArrElement();

	std::cout << std::endl;
	ft_printSeparator("Testing Copy Constructor (cloning emptyTen)", false);
	Array<std::string> cloneEmptyTen(emptyArrTen);
	std::cout << "cloneEmptyTen: ";
	cloneEmptyTen.ft_printArrElement();

	std::cout << std::endl;
	ft_printSeparator("Testing constant Array)", false);
	const Array <std::string> constArr(AMOUNT);
	for (int i = 0; i < AMOUNT; i++)
		std::cout << "constArr[" << i << "]: " << constArr[i] << (i < AMOUNT - 1 ? " " : "");
	std::cout << std::endl;

	std::cout << std::endl;
	ft_printSeparator("Testing exceptions (accesing invalid index)", false);
	try
	{
		unsigned int idx = nomalWordsArr.size();
		std::cout << "normalArrFive[" << (idx - 1) << "]" << nomalWordsArr[idx - 1] << std::endl;
		std::cout << "normalArrFive[" << (idx) << "]" << nomalWordsArr[idx] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//==================================
	std::cout << std::endl;
	ft_printSeparator("My test", false);
	Array<std::string> emptyArr;
	emptyArr.ft_printArrElement();
	Array<std::string> arr3(3);
	for (int i = 0; i < 3; i++)
	{
		std::stringstream ss;
		ss << "MyTest_N_" << (i + 3);
		arr3[i] = ss.str();
	}
	arr3.ft_printArrElement();
	emptyArr = arr3;
	emptyArr.ft_printArrElement();
	// arr3 = emptyArr;
	// arr3.ft_printArrElement();
	//==================================

	return ;
}



int	main(void)
{
	testingInt();
	testingString();
	return (0);
}

//============================================================================
// Include my Example class in the Makefile and add this code:
// #include "Example.hpp"
// static void	testingAdditional(void)
// {
// 	std::cout << std::endl;
// 	ft_printSeparator("Adittional exmaple (Non-const)", true);
// 	Array<Example> normalExampleArr(3);
// 	{
// 		normalExampleArr[0] = Example(1, 1.1, "First");
// 		normalExampleArr[1] = Example(2, 2.2, "Second");
// 		normalExampleArr[2].setInt(3);
// 		normalExampleArr[2].setDouble(3.3);
// 		normalExampleArr[2].setString("Third");
// 	}
// 	std::cout << "normalExampleArr: ";
// 	normalExampleArr.ft_printArrElement();
// 	Array <Example> emptyArrFive(3 + 2);
// 	std::cout << "emptyArrFive: ";
// 	emptyArrFive.ft_printArrElement();
// 	std::cout << "Size of emptyArrFive: " << emptyArrFive.size() << std::endl;
// 	std::cout << std::endl;
// 	ft_printSeparator("Testing Copy assigment operator (emptyArrFive = normalExampleArr)", false);
// 	emptyArrFive = normalExampleArr;
// 	std::cout << "emptyArrFive: ";
// 	emptyArrFive.ft_printArrElement();
// 	std::cout << "Size of emptyArrFive: " << emptyArrFive.size() << std::endl;
// 	std::cout << "Modifying emptyArrFive" << std::endl;
// 	for (unsigned int i = 0; i < emptyArrFive.size(); i++)
// 	{
// 		std::stringstream ss;
// 		ss << "New_example_N_" << (i + 2);
// 		emptyArrFive[i].setInt(i + 2);
// 		emptyArrFive[i].setDouble(i + 2 + 0.1f);
// 		emptyArrFive[i].setString(ss.str());
// 	}
// 	std::cout << "emptyArrFive: ";
// 	emptyArrFive.ft_printArrElement();
// 	std::cout << "normalExampleArr: ";
// 	normalExampleArr.ft_printArrElement();
// 	std::cout << std::endl;
// 	ft_printSeparator("Testing Copy Constructor (cloning emptyTen)", false);
// 	Array<Example> cloneEmptyFive(emptyArrFive);
// 	std::cout << "cloneEmptyTen: ";
// 	cloneEmptyFive.ft_printArrElement();
// 	std::cout << "Modifying cloneEmptyFive" << std::endl;
// 	for (unsigned int i = 0; i < cloneEmptyFive.size(); i++)
// 	{
// 		cloneEmptyFive[i] = Example(123, 123.456, "whatever");
// 	}
// 	std::cout << "cloneEmptyTen: ";
// 	cloneEmptyFive.ft_printArrElement();
// 	std::cout << std::endl;
// 	ft_printSeparator("Testing Copy assigment operator (whatever = cloneEmptyFive)", false);
// 	Array<Example> whatever(2);
// 	whatever.ft_printArrElement();
// 	whatever = cloneEmptyFive;
// 	whatever.ft_printArrElement();
// 	std::cout << std::endl;
// 	ft_printSeparator("Testing constant Array)", false);
// 	const Array <Example> constArr(3);
// 	for (int i = 0; i < 3; i++)
// 		std::cout << "constArr[" << i << "]: " << constArr[i] << std::endl;
// 	std::cout << std::endl;
// 	ft_printSeparator("Testing exceptions (accesing invalid index)", false);
// 	try
// 	{
// 		unsigned int idx = normalExampleArr.size();
// 		std::cout << "normalArrFive[" << (idx - 1) << "]" << normalExampleArr[idx - 1] << std::endl;
// 		std::cout << "normalArrFive[" << (idx) << "]" << normalExampleArr[idx] << std::endl;
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
// 	return ;
// }