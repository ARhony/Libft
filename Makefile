CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

RM = rm -f
FLAGS = -Wall -Wextra -Werror -O3

NORM = norminette

TOTAL_FILES = $(words $(SRCS))
PROGRESS_BAR_LENGTH = 40

CURRENT_PROGRESS = 0

define draw_progress_bar
	$(eval TERMINAL_WIDTH = $(shell tput cols))
	$(eval PROGRESS_BAR_LENGTH = $(shell echo $$(($(TERMINAL_WIDTH) - 16))))
	@printf "\rLIBFT:["
	@perl -e 'printf "%s", "#" x int($1 * $(PROGRESS_BAR_LENGTH) / $(TOTAL_FILES))' $(2)
	@perl -e 'printf "%s", " " x int(($(TOTAL_FILES) - $1) * $(PROGRESS_BAR_LENGTH) / $(TOTAL_FILES))' $(2)
	@printf "] ($(1)/$(TOTAL_FILES))"
endef

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(FLAGS) $< -o $@
	$(eval CURRENT_PROGRESS = $(shell echo $$(($(CURRENT_PROGRESS) + 1))))
	@$(call draw_progress_bar,$(CURRENT_PROGRESS),$(OBJS))

NAME = $(BIN_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@ar rc $@ $^
	@printf "\nLibft Compiled\n"

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@rm -rf $(BIN_DIR)

re: fclean all

norm:
	@$(NORM)

.PHONY: all clean fclean re norm
