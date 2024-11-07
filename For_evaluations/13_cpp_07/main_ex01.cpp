/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:04:31 by marondon          #+#    #+#             */
/*   Updated: 2024/07/24 15:36:45 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define FILLCHAR1 '=' // For printing the Separator.
#define FILLCHAR2 ':' // For printing the Separator.

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
	ft_printSeparator("Testing iter() with ints", true);

	int normalArr[] = { 0, 1, 2, 3, 4};
	const int constArr[] = { 5, 6, 7, 8, 9};

	size_t normalArrSize = sizeof(normalArr) / sizeof(normalArr[0]);
	const size_t constArrSize = sizeof(constArr) / sizeof(constArr[0]);

	ft_printArr(normalArr, normalArrSize, "normalArr");
	ft_printArr(constArr, constArrSize, "constArr");

	std::cout << "normalArr with iter applied" << std::endl;
	iter(normalArr, normalArrSize, ft_incrementAndPrint<int>);
	std::cout << "constArr with iter applied" << std::endl;
	iter(constArr, constArrSize, ft_printArrElement<int>);
	std::cout << "normalArr with iter applied (WTF)" << std::endl;
	iter(&normalArr, normalArrSize, ft_printAddresOfEachElement<int>);
	std::cout << std::endl;
	ft_printArr(normalArr, normalArrSize, "normalArr");
	ft_printArr(constArr, constArrSize, "constArr");

	return ;
}

static void	testingString(void)
{
	std::cout << std::endl;
	ft_printSeparator("Testing iter() with strings", true);

	std::string	nomalWordsArr[] = {"hahaha", "hehehe","hihihi","hohoho","huhuhu" };
	const std::string	constWordsArr[] = {"jajaja", "jejeje","jijiji","jojojo","jujuju" };

	size_t nomalWordsArrSize = sizeof(nomalWordsArr) / sizeof(nomalWordsArr[0]);
	const size_t constWordsArrSize = sizeof(constWordsArr) / sizeof(constWordsArr[0]);

	ft_printArr(nomalWordsArr, nomalWordsArrSize, "nomalWordsArr");
	ft_printArr(constWordsArr, constWordsArrSize, "constWordsArr");

	std::cout << "nomalWordsArr with iter applied" << std::endl;
	iter(nomalWordsArr, nomalWordsArrSize, ft_printArrElement<std::string>);
	std::cout << "constWordsArr with iter applied" << std::endl;
	iter(constWordsArr, constWordsArrSize, ft_printArrElement<std::string>);
	std::cout << "nomalWordsArr with iter applied (WTF)" << std::endl;
	iter(&nomalWordsArr, nomalWordsArrSize, ft_printAddresOfEachElement<std::string>);
	std::cout << std::endl;
	ft_printArr(nomalWordsArr, nomalWordsArrSize, "nomalWordsArr");
	ft_printArr(constWordsArr, constWordsArrSize, "constWordsArr");

	return ;
}

int	main(void)
{
	testingInt();
	testingString();
	return (0);
}

//============================================================================
// Note the following:
// 1) If I dont specify the type of argument for the function call inside iter();
// the compiler cannot know which is the argument type of "F";
// So with code: iter(normalArr, normalArrSize, ft_printArrElement);
// Ill have the following error:
// No matching function for call to 'iter'clang(ovl_no_viable_function_in_call)
// iter.hpp(20, 6): Candidate template ignored: couldn't infer template argument 'F'
// iter.hpp(30, 6): Candidate template ignored: couldn't infer template argument 'F'
// 
// Because Im providing T (e.g: int) but I'm not providing the argument type for
// "F" (ft_printArrElement). Remember that it is: void	ft_printArrElement(const T& arr).
// 
// This iter version works: void	iter(T* addressArr, size_t& sizeArr, void (*f)(T& arr))
// Because I'm telling that the function (*f) will take an argument of type "T".
// 
// So for my new iter version to work: void	iter(T* addressArr, const size_t& sizeArr, F function)
// I need to call it like this: iter(normalArr, normalArrSize, ft_printArrElement);
//============================================================================
// Include my Example class in the Makefile and add this code:
// #include "Example.hpp"
// template <typename T>
// static void	ft_printExampleInfo(const T& something)
// {
// 	std::cout << something << std::endl;
// }
// 
// static void	testingAdditional(void)
// {
// 	std::cout << std::endl;
// 	ft_printSeparator("Adittional exmaple (Non-const)", true);
// 	Example normalExampleArr[] = {
// 		Example(1, 1.1, "First"),
// 		Example(2, 2.2, "Second"),
// 		Example(3, 3.3, "Third"),
// 		Example(),
// 		};
// 	const Example constExampleArr[] = {
// 		Example(1, 1.1, "First"),
// 		Example(2, 2.2, "Second"),
// 		Example(3, 3.3, "Third"),
// 		Example(),
// 	};
// 	size_t normalExampleArrSize = sizeof(normalExampleArr) / sizeof(normalExampleArr[0]);
// 	size_t constExampleArrSize = sizeof(constExampleArr) / sizeof(constExampleArr[0]);
// 	ft_printArr(normalExampleArr, normalExampleArrSize, "normalExampleArr");
// 	ft_printArr(constExampleArr, constExampleArrSize, "constExampleArrArr");
// 	std::cout << "normalExampleArr with iter applied" << std::endl;
// 	iter(normalExampleArr, normalExampleArrSize, ft_incrementAndPrint<Example>);
// 	std::cout << "constExampleArr with iter applied" << std::endl;
// 	iter(constExampleArr, constExampleArrSize, ft_printExampleInfo<Example>);
// 	std::cout << "normalExampleArr with iter applied (WTF)" << std::endl;
// 	iter(&normalExampleArr, normalExampleArrSize, ft_printAddresOfEachElement<Example>);
// 	std::cout << std::endl;
// 	ft_printArr(normalExampleArr, normalExampleArrSize, "normalExampleArr");
// 	ft_printArr(constExampleArr, constExampleArrSize, "constExampleArr");
// 	return ;
// }
