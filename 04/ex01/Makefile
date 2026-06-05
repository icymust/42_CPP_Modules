NAME = animal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Ilib

SRCS = src/main.cpp \
	src/Animal.cpp \
	src/Cat.cpp \
	src/Dog.cpp \
	src/WrongAnimal.cpp \
	src/WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
