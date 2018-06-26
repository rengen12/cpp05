/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amichak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 21:42:00 by amichak           #+#    #+#             */
/*   Updated: 2018/06/26 21:42:00 by amichak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &src);

	~PresidentialPardonForm(void);

	PresidentialPardonForm  &operator= (const PresidentialPardonForm &rhs);

	virtual void            execute(const Bureaucrat &executor) const;

private:
	static const int        _sign;
	static const int        _exec;
};

#endif
