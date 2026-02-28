# build
NAME = hotrace

# directories 
SRCS_DIR = srcs
INC_DIR = includes
BUILD_DIR = build

# flags
CC = cc
CFLAGS = -MMD -MP -Wall -Wextra -Werror -I $(INC_DIR)
MAKEFLAGS += -j $$(nproc)

# sources
SRCS = main.c \
	   helpers/ft_putstr_fd.c \
	   helpers/ft_strcmp.c \
	   helpers/ft_strlen.c \
	   helpers/get_next_line_no_nl.c \
	   token/hash.c \
	   token/linked_list.c \
	   token/token.c

# objects
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	@make all --no-print-directory

# miscellaneous
.PHONY: all clean fclean re
-include $(DEPS)
