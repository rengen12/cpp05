/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 21:42:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/26 21:42:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const int RobotomyRequestForm::_sign = 72;
const int RobotomyRequestForm::_exec = 45;

RobotomyRequestForm::RobotomyRequestForm(void) :
		Form("none", "Robotomy", \
    RobotomyRequestForm::_sign, RobotomyRequestForm::_exec) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
		Form(target, "Robotomy", \
    RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
		Form("none", "Robotomy", \
    RobotomyRequestForm::_sign, RobotomyRequestForm::_exec)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &rhs)
{
	static_cast <void> (rhs);
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= RobotomyRequestForm::_exec && this->isSigned()) {
		std::cout << "*make drill noize*" << std::endl;
		if (rand() % 10 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
		else
			std::cout << "failure." << std::endl;
	}
	else if (!this->isSigned())
		std::cout << "The form isn't signed yet." << std::endl;
	else
		throw Form::GradeTooLowException();
}
