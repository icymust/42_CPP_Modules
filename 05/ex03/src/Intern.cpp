#include "../lib/Intern.hpp"
#include "../lib/ShrubberyCreationForm.hpp"
#include "../lib/RobotomyRequestForm.hpp"
#include "../lib/PresidentialPardonForm.hpp"
#include <iostream>

namespace {
	AForm* createShrubbery(const std::string& target)
	{
		return new ShrubberyCreationForm(target);
	}

	AForm* createRobotomy(const std::string& target)
	{
		return new RobotomyRequestForm(target);
	}

	AForm* createPardon(const std::string& target)
	{
		return new PresidentialPardonForm(target);
	}
}

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
	typedef AForm* (*Factory)(const std::string&);
	const std::string names[] = {
		"shrubbery creation", "robotomy request", "presidential pardon"
	};
	const Factory factories[] = {createShrubbery, createRobotomy, createPardon};

	for (int i = 0; i < 3; ++i) {
		if (name == names[i]) {
			AForm* form = factories[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern couldn't create form: unknown name '" << name << "'" << std::endl;
	return NULL;
}
