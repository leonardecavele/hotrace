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
SRCS =\

# objects
OBJS = $(SRCS:%.c=$(BUILD_DIR)/lib/%.o)
DEPS = $(OBJS:.o=.d)

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# miscellaneous
.PHONY: all clean fclean re
-include $(DEPS)
