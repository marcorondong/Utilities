/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marondon <marondon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:44:08 by marondon          #+#    #+#             */
/*   Updated: 2024/06/27 15:01:24 by marondon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:
		void			setIdea(int index, std::string idea);
		const std::string&	getIdea(int index) const;
		void			printAllIdeas() const;

		// Orthodox Canonical Form parts:
		Brain(); // Defaul Constructor.
		~Brain(); // Defaul Destructor.
		Brain(const Brain& other); // Copy Constructor.
		Brain& operator=(const Brain& other); // Copy Assignment Operator.

	private:
		std::string ideas[100];
};

#endif
