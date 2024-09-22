NAME = so_long

CLR_YLW = \033[0;33m
CLR_STP = \033[m

CC = cc
CFLAGS = -Wall -Werror -Wextra

BUILD_DIR = build

# Library FT

LIBFT = libft.a
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_LINK = -L $(LIBFT_PATH) -l $(patsubst lib%.a,%,$(LIBFT))

# Library MiniLibX

LIBMLX = libmlx.a
LIBMLX_PATH = $(LIBS_PATH)/libmlx
LIBMLX_LINK = -L $(LIBMLX_PATH) -l $(patsubst lib%.a,%,$(LIBMLX))

# Libraries list

LIBS =	$(LIBFT_PATH)/$(LIBFT) \
		$(LIBMLX_PATH)/$(LIBMLX) \

LIBS_PATH = libs
LIBS_LINK = $(LIBFT_LINK) $(LIBMLX_LINK) -l Xext -l X11

# Main Sources

MAIN = so_long.c \

MAIN_PATH = srcs
MAIN_OBJS = $(addprefix $(BUILD_DIR)/,$(MAIN:.c=.o))

# Window Management sources

WIN =	ft_win_setup.c \
		mlx_close_hook.c \

WIN_PATH = $(MAIN_PATH)/win
WIN_OBJS = $(addprefix $(BUILD_DIR)/,$(WIN:.c=.o))

# Build Rules

all: $(NAME)

# Program Build

$(NAME): $(MAIN_OBJS) $(WIN_OBJS) $(HOOK_OBJS) | $(LIBS)
	$(CC) $(CFLAGS) $^ $(LIBFT_LINK) $(LIBMLX_LINK) -o $@

# Main Build

$(BUILD_DIR)/%.o: $(MAIN_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Window Management Build

$(BUILD_DIR)/%.o: $(WIN_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Libraries Build

$(LIBFT_PATH)/$(LIBFT):
	@echo -n "Building $(CLR_YLW)$(notdir $@)$(CLR_STP)... "
	@$(MAKE) -C $(dir $@) > /dev/null 2>&1
	@echo "Done."

$(LIBMLX_PATH)/$(LIBMLX):
	@echo -n "Building $(CLR_YLW)$(notdir $@)$(CLR_STP)... "
	@$(MAKE) -C $(dir $@) > /dev/null 2>&1
	@echo "Done."

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	@$(MAKE) $@ -C $(LIBFT_PATH) > /dev/null 2>&1
	@$(MAKE) $@ -C $(LIBMLX_PATH) > /dev/null 2>&1

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) $@ -C $(LIBFT_PATH) > /dev/null 2>&1
	@$(MAKE) $< -C $(LIBMLX_PATH) > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re