#include "../lib/Bureaucrat.hpp"
#include "../lib/AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ob) : _name(ob._name), _grade(ob._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ob)
{
	if (this != &ob) {
		_grade = ob._grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::upGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::downGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ob)
{
	os << ob.getName() << ", bureaucrat grade " << ob.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(AForm& form) const
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
