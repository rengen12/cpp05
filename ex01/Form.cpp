/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:12:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/25 21:12:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
		_name("no name"),
		_signed(false),
		_signGrade(1),
		_execGrade(1) {}

Form::Form(const std::string &_name, int gradeSign, int gradeExec) :
		_name(_name),
		_signed(false),
		_signGrade(gradeSign),
		_execGrade(gradeExec) {
	if (_signGrade < 1 || _execGrade < 1)
		throw (Form::GradeTooHighException());
	if (_signGrade > 150 || _execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form(void) {}

Form::Form(Form const &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
}

Form &	Form::operator=(Form const & rhs) {

	this->_signed = rhs._signed;
	return *this;
}

const std::string					&Form::getName() const
{
	return (_name);
}

bool								Form::isSigned() const
{
	return (_signed);
}

int									Form::getSignGrade() const
{
	return (_signGrade);
}

int									Form::getExecGrade() const
{
	return (_execGrade);
}

std::ostream						&operator<<(std::ostream &os, Form const &form) {
	os << "Form name " << form.getName() << " status: "
	   << (form.isSigned() ? "signed" : "unsigned") << " grade required to sign "
	   << form.getSignGrade() << " grade required to execute "
	   << form.getExecGrade() << std::endl;
	return (os);
}

void								Form::signForm(void) {
	this->_signed = true;
}

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) {
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException &		Form::GradeTooHighException::operator=(GradeTooHighException const &) {
	return *this;
}

const char* 						Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) {
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException &		Form::GradeTooLowException::operator=(GradeTooLowException const &) {
	return *this;
}

const char* 						Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

void	Form::beSigned(Bureaucrat & src) {

	if (src.getGrade() > this->_signGrade) {
		throw (Form::GradeTooLowException());
	}
	else if (this->_signed)
		std::cout << src.getName() << " cannot sign " << this->_name << " because the form is already signed." << std::endl;
	else
		std::cout << src.getName() << " signs " << this->_name << "." << std::endl;
	this->signForm();
}