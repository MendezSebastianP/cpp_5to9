CC        := c++
CXXFLAGS  := -std=c++98 -Wall -Werror -Wextra -g
DEPFLAGS  := -MMD -MP
FLAGS     := $(CXXFLAGS) $(DEPFLAGS)

SRCS      := 	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
				PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp

TRASH_DIR := .trash
OBJ       := $(patsubst %.cpp,$(TRASH_DIR)/%.o,$(SRCS))
DEP       := $(OBJ:.o=.d)

NAME      := Bureaucrats

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $@

$(TRASH_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -rf $(TRASH_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
