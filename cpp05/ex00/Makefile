CC        := c++
CXXFLAGS  := -std=c++98 -Wall -Werror -Wextra -g
DEPFLAGS  := -MMD -MP
FLAGS     := $(CXXFLAGS) $(DEPFLAGS)

SRCS      := main.cpp \
             Character.cpp \
             I_Character.cpp \
             I_MateriaSource.cpp \
             MateriaSource.cpp \
             Materias/A_Materia.cpp \
             Materias/Cure.cpp \
             Materias/Ice.cpp

TRASH_DIR := .trash
OBJ       := $(patsubst %.cpp,$(TRASH_DIR)/%.o,$(SRCS))
DEP       := $(OBJ:.o=.d)

NAME      := Characters

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
