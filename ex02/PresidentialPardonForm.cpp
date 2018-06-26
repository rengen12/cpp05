/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 21:42:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/26 21:42:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::_sign = 25;
const int PresidentialPardonForm::_exec = 5;

PresidentialPardonForm::PresidentialPardonForm(void) :
		Form("none", "Presidential", \
    PresidentialPardonForm::_sign, PresidentialPardonForm::_exec)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
		Form(target, "Presidential", \
    PresidentialPardonForm::_sign, PresidentialPardonForm::_exec)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &s):
		Form("none", "Presidential", \
    PresidentialPardonForm::_sign, PresidentialPardonForm::_exec)
{
	*this = s;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &rhs)
{
	static_cast <void> (rhs);
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() <= PresidentialPardonForm::_exec && this->isSigned() )
		std::cout << this->getTarget() << " has been pardonned by Zafod Beeblebrox." << std::endl;
	else if (!this->isSigned())
		std::cout << "The form isn't signed yet." << std::endl;
	else
		throw Form::GradeTooLowException();
}
