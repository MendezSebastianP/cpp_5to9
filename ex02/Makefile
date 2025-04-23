SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

NAME = FragTrap

TRASH_DIR = .trash

OBJ = $(addprefix $(TRASH_DIR)/, $(SRC:.cpp=.o))

FLAGS = -std=c++98 -Wall -Werror -Wextra -g

CC = c++

$(TRASH_DIR):
	mkdir -p $(TRASH_DIR)

$(TRASH_DIR)/%.o: %.cpp | $(TRASH_DIR)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(TRASH_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
