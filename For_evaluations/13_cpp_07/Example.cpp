/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:36:24 by marondon          #+#    #+#             */
/*   Updated: 2024/07/19 15:36:12 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Example.hpp"
#include <iostream>

int		Example::getInt() const
{
	return (_exampleInt);
}

void	Example::setInt(const int toSet)
{
	_exampleInt = toSet;
}

double	Example::getDouble() const
{
	return (_exampleDouble);
}

void	Example::setDouble(const double toSet)
{
	_exampleDouble = toSet;
}

std::string	Example::getString() const
{
	return (_exampleString);
}

void	Example::setString(const std::string& toSet)
{
	_exampleString = toSet;
}

Example::Example(int intToSet, double doubleToSet, std::string stringToSet)
 : _exampleInt(intToSet), _exampleDouble(doubleToSet), _exampleString(stringToSet) {}

/* ========================= Comparison Operators ========================= */
bool	Example::operator>(const Example& other) const
{
	short	countA = 0;
	short	countB = 0;
	_exampleInt > other._exampleInt ? countA++ : countB++;
	_exampleDouble > other._exampleDouble ? countA++ : countB++;
	_exampleString.length() > other._exampleString.length() ? countA++ : countB++;
	// std::cout << "operator>: countA: [" << countA << "], countB: [" << countB << "]." << std::endl;
	return (countA > countB ? true : false);
}

bool	Example::operator<(const Example& other) const
{
	short	countA = 0;
	short	countB = 0;
	_exampleInt < other._exampleInt ? countA-- : countB--;
	_exampleDouble < other._exampleDouble ? countA-- : countB--;
	_exampleString.length() < other._exampleString.length() ? countA-- : countB--;
	// std::cout << "operator<: countA: [" << countA << "], countB: [" << countB << "]." << std::endl;
	return (countA < countB ? true : false);
}

bool	Example::operator>=(const Example& other) const
{
	short	countA = 0;
	short	countB = 0;
	_exampleInt >= other._exampleInt ? countA++ : countB++;
	_exampleDouble >= other._exampleDouble ? countA++ : countB++;
	_exampleString.length() >= other._exampleString.length() ? countA++ : countB++;
	return (countA >= countB ? true : false);
}

bool	Example::operator<=(const Example& other) const
{
	short	countA = 0;
	short	countB = 0;
	_exampleInt <= other._exampleInt ? countA-- : countB--;
	_exampleDouble <= other._exampleDouble ? countA-- : countB--;
	_exampleString.length() <= other._exampleString.length() ? countA-- : countB--;
	return (countA <= countB ? true : false);
}

bool	Example::operator==(const Example& other) const
{
	return (_exampleInt == other._exampleInt
			&& _exampleDouble == other._exampleDouble
			&& _exampleString == other._exampleString);
}

bool	Example::operator!=(const Example& other) const
{
	return (_exampleInt != other._exampleInt
			|| _exampleDouble != other._exampleDouble
			|| _exampleString != other._exampleString);
}

Example&	Example::operator++(void)
{
	_exampleInt++;
	_exampleDouble++;
	return (*this);
}

Example	Example::operator++(int)
{
	Example	tmp = *this;
	_exampleInt++;
	_exampleDouble++;
	return (tmp);
}

/* ===================== Overloaded insertion operator ==================== */
std::ostream&	operator<<(std::ostream& out, const Example& object)
{
	out << "Int: [" << object.getInt() << "]. ";
	out << "Double: [" << object.getDouble() << "]. ";
	out << "String: [" << object.getString() << "]";
	return (out);
}

/* ===================== Orthodox Canonical Form parts ==================== */
// Default Constructor.
Example::Example()
	: _exampleInt(42), _exampleDouble(4.2), _exampleString("forty two") {}

// Destructor.
Example::~Example() {}

// Copy Constructor.
Example::Example(const Example& other)
	: _exampleInt(other._exampleInt), _exampleDouble(other._exampleDouble),
	_exampleString(other._exampleString) {}

// Copy Assignment Operator.
Example&	Example::operator=(const Example& other)
{
	if (this != &other)
	{
		_exampleInt = other._exampleInt;
		_exampleDouble = other._exampleDouble;
		_exampleString = other._exampleString;
	}
	return (*this);
}
