/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:46:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/25 19:46:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;

public:
	Bureaucrat(const std::string &_name, int _grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);
	Bureaucrat			&operator=(Bureaucrat const &rhs);

	const std::string	&getName() const;
	int					getGrade() const;
	void				incrementGrade(void);
	void				decrementGrade(void);
	void				signForm(Form &form) const;

	class	GradeTooHighException: public std::exception
	{
	public:
		GradeTooHighException(void);
		~GradeTooHighException(void) throw();
		GradeTooHighException(GradeTooHighException const &src);
		GradeTooHighException	&operator=(GradeTooHighException const &rhs);

		virtual char const		*what(void) const throw();
	};

	class	GradeTooLowException: public std::exception
	{
	public:
		GradeTooLowException(void);
		~GradeTooLowException(void) throw();
		GradeTooLowException(GradeTooLowException const &src);
		GradeTooLowException	&operator=(GradeTooLowException const &rhs);

		virtual char const		*what(void) const throw();
	};

};

std::ostream			&operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
