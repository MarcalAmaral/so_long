# tool macros
CC = cc
CFLAGS = -Wall -Werror -Wextra

# path macros
BIN_PATH = .
OBJ_PATH = obj
SRC_PATH = src
PATH_MLX = ./lib/MLX42
PATH_MLXLIB = $(PATH_MLX)/build/libmlx42.a -ldl -lm -lpthread -lglfw
PATH_LIBFT = ./lib/libft
PATH_LIBFTLIB = $(PATH_LIBFT)/libft.a

# compile macros
TARGET_NAME = so_long # FILL: target name
TARGET = $(BIN_PATH)/$(TARGET_NAME)

# src files & obj files	
FILES = draw_map \
		ft_readmap \
		ft_readmap_utils \
		game_init \
		handle_collectables \
		handle_image \
		handle_input \
		handle_movements \
		main \

OBJ = $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(FILES)))
INCLUDE = -I ./inc -I $(PATH_MLX)/include

# clean files list
DISTCLEAN_LIST = $(OBJ)
CLEAN_LIST = $(TARGET) \
			$(DISTCLEAN_LIST)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(LIBFT) $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(PATH_MLXLIB) $(PATH_LIBFTLIB)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CC) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C $(PATH_LIB)

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_PATH) $(OBJ_PATH) $(DBG_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: debug
debug: $(TARGET_DEBUG)

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)

.PHONY: fclean
fclean:
	@echo CLEAN $(DISTCLEAN_LIST)
	@rm -f $(DISTCLEAN_LIST)