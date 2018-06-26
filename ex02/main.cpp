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

#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat                    b1("B1", 71);
	Bureaucrat                    b2("B2", 40);
	Bureaucrat                    b3("B3", 2);
	ShrubberyCreationForm         f1("ShrubberyCreationForm");
	RobotomyRequestForm           f2("RobotomyRequestForm");
	PresidentialPardonForm        f3("PresidentialPardonForm");

	try {
		b1.signForm(f1);
		b1.signForm(f2);
		b1.signForm(f3);
		b1.executeForm(f1);
		b1.executeForm(f2);
		b1.executeForm(f3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		b2.signForm(f1);
		b2.signForm(f2);
		b2.signForm(f3);
		b2.executeForm(f1);
		b2.executeForm(f2);
		b2.executeForm(f3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		b3.signForm(f1);
		b3.signForm(f2);
		b3.signForm(f3);
		b3.executeForm(f1);
		b3.executeForm(f2);
		b3.executeForm(f3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}