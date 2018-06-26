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

	Form form("Form", 110, 40);
	Form form2("Form2", 149, 1);
	Form form3("Form3", 50, 10);
	Bureaucrat b1 = Bureaucrat("B", 1);
	std::cout << b1;
	Bureaucrat b2 = Bureaucrat("BB", 150);
	std::cout << b2;

	try {
		std::cout << std::endl << "b1 increment" << std::endl;
		b1.incrementGrade();
		std::cout << b1;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << std::endl << "b2 decrement" << std::endl;
		b2.decrementGrade();
		std::cout << b2;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << form;
	std::cout << form2;
	std::cout << form3;
	try {
		b1.signForm(form);
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b1.signForm(form);
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		form2.beSigned(b1);
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		form3.beSigned(b2);
	}
	catch (Form::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
