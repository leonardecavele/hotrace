### CONSTANTS
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

NAME		=	hotrace

INC_DIR		=	includes

SRC_FILES	= 	main.c \
				writer.c \
				is_interactive.c \
				helpers/ft_putstr_fd.c \
				helpers/ft_strcmp.c \
				helpers/ft_strlen.c \
				helpers/get_next_line_no_nl.c \
				helpers/ft_memcpy.c \
				helpers/ft_min_max.c \
				token/hash.c \
				token/linked_list.c \
				token/token.c \
				token/pool.c

SRC_DIR		=	srcs

### DERIVED CONSTANTS
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= 	$(SRCS:.c=.o)
DEPS		=	$(SRCS:.c=.d)

-include $(DEPS)

.DEFAULT_GOAL := all

### COLORS
COLOR_YELLOW	=	\033[1;33m
COLOR_BOLD		=	\033[1m
COLOR_END		=	\033[0m

TITLE 			= 	[$(COLOR_YELLOW)🔥 - hotrace$(COLOR_END)]

### RULES
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(TITLE) 🔗​ Linking binary $(COLOR_BOLD)$@$(COLOR_END)"
	@$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	@echo "$(TITLE) 🔨 Compiling $(COLOR_BOLD)$<$(COLOR_END)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -c $< -o $@

clean:
	@echo "$(TITLE) 🧹 Cleaning temporary files"
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@echo "$(TITLE) 🧹 Cleaning binaries"
	@$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re


sanitize: CFLAGS += -g3 -fsanitize=address
sanitize: re

.PHONY = all clean fclean re debug sanitize
