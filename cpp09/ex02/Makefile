CC        := c++
CXXFLAGS  := -std=c++98 -Wall -Werror -Wextra -g
DEPFLAGS  := -MMD -MP
FLAGS     := $(CXXFLAGS) $(DEPFLAGS)

SRCS      := main.cpp PmergeMe.cpp

TRASH_DIR := .trash
OBJ       := $(patsubst %.cpp,$(TRASH_DIR)/%.o,$(SRCS))
DEP       := $(OBJ:.o=.d)

NAME      := PmergeMe

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

# --- Development build: drop all -W flags, keep -std and -g
dev: CXXFLAGS := $(filter-out -Wall -Werror -Wextra,$(CXXFLAGS))
dev: FLAGS    := $(CXXFLAGS) $(DEPFLAGS)
dev: re

.PHONY: all clean fclean re dev

# ./PmergeMe "$(shuf -i 0-26 -n 27 | xargs)" > results.txt