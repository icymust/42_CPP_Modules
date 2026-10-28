#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main()
{
	try
	{
		std::cout << "=== 1. Construction and output ===" << std::endl;
		Form defaultForm;
		Form permit("Permit", 50, 25);
		Bureaucrat junior("Junior", 51);
		Bureaucrat senior("Senior", 50);
		std::cout << defaultForm << std::endl;
		std::cout << permit << std::endl;
		std::cout << junior << std::endl;
		std::cout << senior << std::endl;

		std::cout << "\n=== 2. beSigned: insufficient grade ===" << std::endl;
		try
		{
			permit.beSigned(junior);
			std::cout << "ERROR: expected an exception" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << permit << std::endl;

		std::cout << "\n=== 3. beSigned: equal grade succeeds ===" << std::endl;
		permit.beSigned(senior);
		std::cout << permit << std::endl;

		std::cout << "\n=== 4. Copy and assignment ===" << std::endl;
		Form copy(permit);
		Form other("Other", 100, 75);
		other = permit;
		std::cout << copy << std::endl;
		std::cout << other << std::endl;

		std::cout << "\n=== 5. signForm: refusal and success ===" << std::endl;
		Form request("Request", 50, 25);
		junior.signForm(request);
		std::cout << request << std::endl;
		senior.signForm(request);
		std::cout << request << std::endl;

		std::cout << "\n=== 6. Invalid signing / execution grades ===" << std::endl;
		const int signGrades[] = {0, 151, 50, 50};
		const int executeGrades[] = {50, 50, 0, 151};
		for (int i = 0; i < 4; ++i)
		{
			std::cout << "Sign: " << signGrades[i]
				<< ", execute: " << executeGrades[i] << std::endl;
			try
			{
				Form invalid("Invalid", signGrades[i], executeGrades[i]);
				std::cout << "ERROR: expected an exception" << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
