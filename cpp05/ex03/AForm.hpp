/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:02:16 by mazaid            #+#    #+#             */
/*   Updated: 2025/11/25 17:50:32 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
	const std::string name;
	bool issigned;
	const int signGrade;
	const int execGrade;

	public:

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	AForm();
	AForm(const std::string &name, const int signGrade, const int execGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	std::string getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
    void checkExecutable(Bureaucrat const &executor) const;
};
std::ostream &operator<<(std::ostream &out, const AForm &form);


#endif
