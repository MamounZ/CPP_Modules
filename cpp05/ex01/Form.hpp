/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:02:16 by mazaid            #+#    #+#             */
/*   Updated: 2025/11/23 20:02:17 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
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

	Form();
	Form(const std::string &name, const int signGrade, const int execGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	std::string getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
};
std::ostream &operator<<(std::ostream &out, const Form &form);


#endif
