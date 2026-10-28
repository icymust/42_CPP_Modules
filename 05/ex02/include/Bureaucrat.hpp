#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& ob);
	Bureaucrat& operator=(const Bureaucrat& ob);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void upGrade();
	void downGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	void signForm(AForm& form) const;
	void executeForm(const AForm& form) const;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ob);


#endif
