/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 21:42:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/26 21:42:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(void);

	ShrubberyCreationForm(std::string target);

	ShrubberyCreationForm(const ShrubberyCreationForm &src);

	~ShrubberyCreationForm(void);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	virtual void execute(const Bureaucrat &executor) const;

private:
	static const int _sign;
	static const int _exec;
};

#endif
