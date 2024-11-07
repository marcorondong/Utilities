/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:55:26 by marondon          #+#    #+#             */
/*   Updated: 2024/07/24 19:29:41 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
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

static void	testMandatory(void)
{
	std::cout << std::endl;
	ft_printSeparator("Example from guideline", true);

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	//=================================
	const int int1 = 2;
	const int int2 = 3;
	::swap(&int1, &int2 );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	//=================================

	return ;
}

int	main(void)
{
	testMandatory();
	return (0);
}

//============================================================================
// Include my Example class in the Makefile and add this code:
// #include "Example.hpp"
// static void	test01(void)
// {
// 	std::cout << std::endl;
// 	ft_printSeparator("Adittional exmaple (Non-const)", true);
// 	Example a;
// 	Example b(3, 4.0, "five");
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	// std::cout << "a < b ?: " << (a < b) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return ;
// }
// 
// static void	test02(void)
// {
// 	std::cout << std::endl;
// 	ft_printSeparator("Adittional exmaple (Const)", true);
// 	const Example a;
// 	const Example b(3, 4.0, "five");
// 	// ::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	// std::cout << "a < b ?: " << (a < b) << std::endl;
// 	const std::string c = "chaine1";
// 	const std::string d = "chaine2";
// 	// ::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return ;
// }
