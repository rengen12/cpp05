/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:46:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/25 19:46:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int 	main(void) {

	try {
		Bureaucrat b("John", 0);
		std::cout << b << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat j("John", 149);
		std::cout << j << std::endl;
		j.decrementGrade();
		j.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
