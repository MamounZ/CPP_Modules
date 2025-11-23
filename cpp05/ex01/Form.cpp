/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:02:12 by mazaid            #+#    #+#             */
/*   Updated: 2025/11/23 20:20:59 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}
const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
Form::Form():name("unknown"), signGrade(150), execGrade(150)
{
	issigned = 0;
}
Form::Form(const std::string &name, const int signGrade, const int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	issigned = false;
}
Form::Form(const Form &other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
	*this = other;
}
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		issigned = other.issigned;
	}
	return (*this);
}

Form::~Form()
{
}
std::string Form::getName() const
{
	return (this->name);
}

bool Form::isSigned() const
{
	return (this->issigned);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

int Form::getExecGrade() const
{
	return (this->execGrade);
}
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->issigned = true;
}
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName()
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", sign grade: " << form.getSignGrade()
		<< ", exec grade: " << form.getExecGrade();
	return out;
}
