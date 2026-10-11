#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "=== 1. Construction and getters ===" << std::endl;
		Bureaucrat defaultBureaucrat;
		Bureaucrat martin("Martin", 42);
		std::cout << defaultBureaucrat << std::endl;
		std::cout << martin.getName() << ": " << martin.getGrade() << std::endl;

		std::cout << "\n=== 2. Promotion and demotion ===" << std::endl;
		martin.upGrade();
		std::cout << martin << std::endl; // Grade 41
		martin.downGrade();
		std::cout << martin << std::endl; // Grade 42

		std::cout << "\n=== 3. Copy and assignment ===" << std::endl;
		Bureaucrat copy(martin);
		Bureaucrat other("Other", 100);
		other = martin;
		std::cout << copy << std::endl; // Name and grade copied
		std::cout << other << std::endl; // Own name, grade 42

		std::cout << "\n=== 4. Invalid constructor grades ===" << std::endl;
		const int grades[] = {0, 151};
		for (int i = 0; i < 2; ++i)
		{
			std::cout << "Grade: " << grades[i] << std::endl;
			try
			{
				Bureaucrat invalid("Invalid", grades[i]);
				std::cout << "ERROR: expected an exception" << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		std::cout << "\n=== 5. Promotion beyond grade 1 ===" << std::endl;
		Bureaucrat highest("Highest", 1);
		try
		{
			highest.upGrade();
			std::cout << "ERROR: expected an exception" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << highest << std::endl; // Still grade 1

		std::cout << "\n=== 6. Demotion beyond grade 150 ===" << std::endl;
		Bureaucrat lowest("Lowest", 150);
		try
		{
			lowest.downGrade();
			std::cout << "ERROR: expected an exception" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << lowest << std::endl; // Still grade 150
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
