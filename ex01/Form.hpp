/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:12:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/25 21:12:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	bool 				_signed;
	int const 			_signGrade;
	int const 			_execGrade;

public:
	Form(void);
	Form(const std::string &_name, int gradeSign, int gradeExec);
	~Form(void);
	Form(Form const &);
	Form &	operator=(Form const & rhs);

	const std::string	&getName() const;
	bool				isSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				signForm(void);
	void				beSigned(Bureaucrat & src);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		~GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const &);
		GradeTooHighException&	operator=(GradeTooHighException const &);

		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		~GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const &);
		GradeTooLowException&	operator=(GradeTooLowException const &);

		virtual const char* what() const throw();
	};

};

std::ostream	&operator<<(std::ostream &os, Form const &form);

#endif
