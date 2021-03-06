/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:46:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/25 19:46:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
		_name(name) {
	if (grade < 1) {
		throw (Bureaucrat::GradeTooHighException());
	} else if (grade > 150) {
		throw (Bureaucrat::GradeTooLowException());
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat					&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return (*this);
}

const		std::string &Bureaucrat::getName() const {
	return _name;
}

int			Bureaucrat::getGrade() const {
	return _grade;
}

void		Bureaucrat::incrementGrade(void) {
	if (this->_grade <= 1) {
		throw (Bureaucrat::GradeTooHighException());
	}
	this->_grade--;
}

void		Bureaucrat::decrementGrade(void) {
	if (this->_grade >= 150) {
		throw (Bureaucrat::GradeTooLowException());
	}
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const							*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const &rhs)
{
	std::exception::operator=(rhs);
	return (*this);
}

char const							*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}
