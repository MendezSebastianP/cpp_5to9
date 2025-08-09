CC        := c++
CXXFLAGS  := -Wall -Wextra -Werror -std=c++98 -O2 # optimizations ~10x faster
DEPFLAGS  := -MMD -MP
FLAGS     := $(CXXFLAGS) $(DEPFLAGS)

SRCS      := main.cpp PmergeMe.cpp

TRASH_DIR := .trash
OBJ       := $(patsubst %.cpp,$(TRASH_DIR)/%.o,$(SRCS))
DEP       := $(OBJ:.o=.d)

NAME      := PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $(OBJ)

$(TRASH_DIR)/%.o: %.cpp PmergeMe.hpp
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(TRASH_DIR)

re: fclean all

.PHONY: all clean fclean re
