#include "../lib/Intern.hpp"
#include "../lib/AForm.hpp"
#include "../lib/Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>

static void demonstrate(const Intern& intern, const std::string& name,
	const std::string& target)
{
	AForm* form = intern.makeForm(name, target);
	if (!form)
		throw std::runtime_error("Known form was not created");
	try {
		std::cout << *form << std::endl;
		Bureaucrat chief("Chief", 1);
		chief.executeForm(*form);
		chief.signForm(*form);
		if (!form->getIsSigned())
			throw std::runtime_error("Signing failed");
		form->execute(chief);
		chief.executeForm(*form);
	} catch (...) {
		delete form;
		throw;
	}
	delete form;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	try {
		Intern intern;
		Intern copy(intern);
		Intern assigned;
		assigned = copy;

		std::cout << "=== 1. Shrubbery ===" << std::endl;
		demonstrate(intern, "shrubbery creation", "garden");
		std::ifstream file("garden_shrubbery");
		std::string line;
		if (!std::getline(file, line) || line.empty())
			throw std::runtime_error("Shrubbery file is missing or empty");

		std::cout << "\n=== 2. Robotomy ===" << std::endl;
		demonstrate(copy, "robotomy request", "Bender");

		std::cout << "\n=== 3. Pardon ===" << std::endl;
		demonstrate(assigned, "presidential pardon", "Arthur Dent");

		std::cout << "\n=== 4. Unknown form ===" << std::endl;
		AForm* unknown = intern.makeForm("coffee request", "Office");
		if (unknown) {
			delete unknown;
			throw std::runtime_error("Unknown form should return NULL");
		}
		std::cout << "No object created; pointer is NULL" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
