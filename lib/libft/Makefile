# Project name
NAME = libft.a

# tool macros
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(HEADER)

# path macros
SRC_PATH := src
OBJ_PATH := obj
HEADER := inc

# src files & object files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))

# Object files
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

all: $(NAME)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)/*.o

fclean: clean
	rm -rf *$(NAME)

re: fclean all
