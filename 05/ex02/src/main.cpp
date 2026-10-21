#include "../lib/Bureaucrat.hpp"
#include "../lib/AForm.hpp"
#include "../lib/ShrubberyCreationForm.hpp"
#include "../lib/RobotomyRequestForm.hpp"
#include "../lib/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>

static void demonstrate(AForm& form)
{
	std::cout << "\n=== " << form.getName() << " ===" << std::endl;
	std::cout << form << std::endl;
	Bureaucrat signer("Signer", form.getGradeToSign());
	Bureaucrat executor("Executor", form.getGradeToExecute());
	Bureaucrat junior("Junior", form.getGradeToSign() + 1);

	std::cout << "1. Execution before signing" << std::endl;
	try {
		form.execute(executor);
		throw std::logic_error("Unsigned form was executed");
	} catch (const AForm::NotSignedException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "2. Signing: refusal and success" << std::endl;
	junior.signForm(form);
	if (form.getIsSigned())
		throw std::logic_error("Insufficient grade signed the form");
	signer.signForm(form);
	if (!form.getIsSigned())
		throw std::logic_error("Signing failed");

	std::cout << "3. Execution with insufficient grade" << std::endl;
	Bureaucrat weakExecutor("Weak executor", form.getGradeToExecute() + 1);
	try {
		form.execute(weakExecutor);
		throw std::logic_error("Insufficient grade executed the form");
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	weakExecutor.executeForm(form);

	std::cout << "4. Execution at the required grade" << std::endl;
	form.execute(executor);
	executor.executeForm(form);
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	try {
		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Arthur Dent");
		demonstrate(shrubbery);
		std::ifstream file("home_shrubbery");
		std::string line;
		if (!std::getline(file, line) || line.empty())
			throw std::runtime_error("Shrubbery file is missing or empty");
		demonstrate(robotomy);
		demonstrate(pardon);

		std::cout << "\n=== Copy and assignment ===" << std::endl;
		PresidentialPardonForm copy(pardon);
		PresidentialPardonForm assigned("Other target");
		assigned = pardon;
		std::cout << copy << std::endl;
		Bureaucrat chief("Chief", 1);
		chief.executeForm(assigned);

		std::cout << "\n=== Virtual destructor ===" << std::endl;
		AForm* form = new ShrubberyCreationForm("temporary");
		delete form;
	} catch (const std::exception& e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
