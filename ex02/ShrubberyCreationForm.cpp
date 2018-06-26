/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 21:42:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/26 21:42:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const int ShrubberyCreationForm::_sign = 145;
const int ShrubberyCreationForm::_exec = 137;

ShrubberyCreationForm::ShrubberyCreationForm(void) :
		Form("Anonymous", "Shrubbery", \
	ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
		Form(target, "Shrubbery", \
	ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
		Form("Anonymous", "Shrubbery", \
	ShrubberyCreationForm::_sign, ShrubberyCreationForm::_exec)
{
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm
&ShrubberyCreationForm::operator= (const ShrubberyCreationForm &rhs)
{
	static_cast <void> (rhs);
	return (*this);
}

void
ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream  file;

	if (executor.getGrade() <= ShrubberyCreationForm::_exec && this->isSigned())
	{
		file.open(getTarget() + "_shrubbery",
				  std::ofstream::out | std::ofstream::trunc);
		if (file.fail())
		{
			std::cerr << "Error openning the outfile" << std::endl;
		}
		file << "      ccee88oo " << std::endl;
		file << "   C8O8O8Q8PoOb o8oo " << std::endl;
		file << "  dOB69QO8PdUOpugoO9bD " << std::endl;
		file << " CgggbU8OU qOp qOdoUOdcb " << std::endl;
		file << "     6OuU  /p u gcoUodpP " << std::endl;
		file << "       \\\\//  /douUP " << std::endl;
		file << "         \\\\//// " << std::endl;
		file << "          |||/" << std::endl;
		file << "          ||||/ " << std::endl;
		file << "          ||||| " << std::endl;
		file << "    .....//||||\\.... " << std::endl;
		file.close();
	}
	else if (!this->isSigned())
		std::cout << "The form isn't signed yet." << std::endl;
	else
		throw Form::GradeTooLowException();
}
