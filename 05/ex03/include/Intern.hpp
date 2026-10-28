#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern {
private:
	AForm* createShrubbery(const std::string& target) const;
	AForm* createRobotomy(const std::string& target) const;
	AForm* createPardon(const std::string& target) const;
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& name, const std::string& target) const;
};

#endif
