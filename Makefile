NAME := push_swap
CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f

SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := lib

LIBFT_DIR := $(LIB_DIR)/libft
LIBFT := libft.a
INCLUDE_DIR := include $(LIBFT_DIR)/include

SRC_FILES := ft_get_input.c\
	operations1.c\
	operations2.c\
	push_swap.c\
	short_sorts.c\
	sort_left.c\
	sort_right.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
INCLUDE_PATH := $(addprefix -I, $(INCLUDE_DIR))
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_DIR)/$(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_PATH) -c -o $@ $<

$(LIBFT_DIR)/$(LIBFT):
	@make -C $(LIBFT_DIR) all

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re