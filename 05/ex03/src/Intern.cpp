#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

AForm* Intern::createShrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) const
{
	return new PresidentialPardonForm(target);
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
	typedef AForm* (Intern::*Factory)(const std::string&) const;
	const std::string names[] = {
		"shrubbery creation", "robotomy request", "presidential pardon"
	};
	const Factory factories[] = {
		&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPardon
	};

	for (int i = 0; i < 3; ++i) {
		if (name == names[i]) {
			AForm* form = (this->*factories[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern couldn't create form: unknown name '" << name << "'" << std::endl;
	return NULL;
}
