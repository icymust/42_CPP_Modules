NAME = bureaucrut
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Ilib

SRCS = src/Bureaucrat.cpp src/main.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp \
       src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(wildcard lib/*.hpp)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
