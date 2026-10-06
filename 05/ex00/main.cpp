#include "Bureaucrat.hpp"
#include <sstream>

static int failures = 0;

static void check(bool condition, const char* description)
{
	std::cout << (condition ? "[OK] " : "[FAIL] ") << description << std::endl;
	if (!condition)
		++failures;
}

static void testInvalidGrade(int grade)
{
	try
	{
		Bureaucrat invalid("Invalid", grade);
		check(false, "Invalid constructor must throw");
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		check(grade < 1, "Constructor throws GradeTooHighException");
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		check(grade > 150, "Constructor throws GradeTooLowException");
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	try
	{
		Bureaucrat defaultBureaucrat;
		check(defaultBureaucrat.getGrade() >= 1
			&& defaultBureaucrat.getGrade() <= 150, "Default grade is valid");

		Bureaucrat martin("Martin", 42);
		check(martin.getName() == "Martin" && martin.getGrade() == 42,
			"Constructor and getters");
		martin.upGrade();
		check(martin.getGrade() == 41, "Promotion: 42 -> 41");
		martin.downGrade();
		check(martin.getGrade() == 42, "Demotion: 41 -> 42");

		Bureaucrat highest("Highest", 2);
		highest.upGrade();
		check(highest.getGrade() == 1, "Promotion to grade 1");
		try
		{
			highest.upGrade();
			check(false, "Promotion beyond grade 1 must throw");
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			check(highest.getGrade() == 1, "Failed promotion preserves grade 1");
			std::cout << e.what() << std::endl;
		}

		Bureaucrat lowest("Lowest", 149);
		lowest.downGrade();
		check(lowest.getGrade() == 150, "Demotion to grade 150");
		try
		{
			lowest.downGrade();
			check(false, "Demotion beyond grade 150 must throw");
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			check(lowest.getGrade() == 150, "Failed demotion preserves grade 150");
			std::cout << e.what() << std::endl;
		}

		testInvalidGrade(-1);
		testInvalidGrade(0);
		testInvalidGrade(151);

		Bureaucrat copy(martin);
		check(copy.getName() == martin.getName() && copy.getGrade() == 42,
			"Copy constructor copies name and grade");
		copy.upGrade();
		check(martin.getGrade() == 42, "Copy changes independently");

		Bureaucrat other("Other", 100);
		other = martin;
		check(other.getName() == "Other" && other.getGrade() == 42,
			"Assignment copies grade and preserves destination name");
		Bureaucrat& alias = other;
		other = alias;
		check(other.getName() == "Other" && other.getGrade() == 42,
			"Self-assignment preserves state");

		std::ostringstream output;
		output << martin;
		check(output.str() == "Martin, bureaucrat grade 42.",
			"Output matches subject format, including final dot");
		std::cout << martin << std::endl;
	}
	catch (const std::exception& e)
	{
		check(false, "Unexpected exception");
		std::cout << e.what() << std::endl;
	}
	std::cout << "Failures: " << failures << std::endl;
	return failures ? 1 : 0;
}
