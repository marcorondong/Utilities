/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Example.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:29:29 by marondon          #+#    #+#             */
/*   Updated: 2024/07/19 15:34:34 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_HPP
# define EXAMPLE_HPP

# include <string>

class Example
{
	public:
		int			getInt() const;
		void		setInt(const int toSet);
		double		getDouble() const;
		void		setDouble(const double toSet);
		std::string	getString() const;
		void		setString(const std::string& toSet);
		Example(int intToSet, double doubleToSet, std::string stringToSet);
		// Operators (comaprison and increment).
		bool		operator>(const Example& other) const;
		bool		operator<(const Example& other) const;
		bool		operator>=(const Example& other) const;
		bool		operator<=(const Example& other) const;
		bool		operator==(const Example& other) const;
		bool		operator!=(const Example& other) const;
		Example&	operator++(void);
		Example		operator++(int);
		// Orthodox Canonical Form parts:
		Example(); // Default Constructor.
		~Example(); // Destructor.
		Example(const Example& other); // Copy constructor.
		Example& operator=(const Example& other); // Copy Asignment Operator.

	private:
		int _exampleInt;
		double _exampleDouble;
		std::string _exampleString;
};

// Overloaded insertion operator.
std::ostream&	operator<<(std::ostream& out, const Example& object);

#endif
