/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:02:25 by marondon          #+#    #+#             */
/*   Updated: 2024/06/27 16:30:38 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
#include "Brain.hpp"

# define DOG_TYPE "Dog"
# define DOG_SOUND "Guau Guau"

class Dog : public AAnimal
{
	public:
		void	makeSound() const;
		void	think(int index, const std::string& idea);
		void	expressThoughts(int mode, int index) const;

		// Orthodox Canonical Form parts:
		Dog(); // Defaul Constructor.
		~Dog(); // Default Destructor.
		Dog(const Dog& other); // Copy Constructor.
		Dog&	operator=(const Dog& other); // Copy Assignment Operator.

	private:
		Brain* _brain;
};

#endif
