# build
NAME = hotrace
LIBFT_A = $(LIBFT_DIR)/libft.a

# directories 
SRCS_DIR = srcs
INC_DIR = includes
BUILD_DIR = build
LIBFT_DIR = libft

# flags
CC = cc
CFLAGS = -MMD -MP -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR)/includes
MAKEFLAGS += -j $$(nproc)

# sources
SRCS =\

# objects
OBJS = $(SRCS:%.c=$(BUILD_DIR)/lib/%.o)
DEPS = $(OBJS:.o=.d)

# rules
all: $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

# miscellaneous
.PHONY: all clean fclean re
-include $(DEPS)
