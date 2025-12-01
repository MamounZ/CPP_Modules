/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:02:12 by mazaid            #+#    #+#             */
/*   Updated: 2025/11/25 17:55:08 by mazaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}
AForm::AForm():name("unknown"), signGrade(150), execGrade(150)
{
	issigned = 0;
}
AForm::AForm(const std::string &name, const int signGrade, const int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	issigned = false;
}
AForm::AForm(const AForm &other) : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade)
{
	*this = other;
}
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		issigned = other.issigned;
	}
	return (*this);
}

AForm::~AForm()
{
}
std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::isSigned() const
{
	return (this->issigned);
}

int AForm::getSignGrade() const
{
	return (this->signGrade);
}

int AForm::getExecGrade() const
{
	return (this->execGrade);
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->issigned = true;
}
void AForm::checkExecutable(Bureaucrat const &executor) const
{
	if (!this->issigned)
		throw FormNotSignedException();
	if (executor.getGrade() > this->execGrade)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form " << form.getName()
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", sign grade: " << form.getSignGrade()
		<< ", exec grade: " << form.getExecGrade();
	return out;
}
