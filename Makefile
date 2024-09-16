NAME = so_long

CLR_YLW = \033[0;33m
CLR_STP = \033[m

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBS_DIR = libs

LIBFT_NAME = libft.a
LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT_LINK = -L $(LIBFT_DIR) -l $(patsubst lib%.a,%,$(LIBFT_NAME))

LIBMLX_NAME = libmlx.a
LIBMLX_DIR = $(LIBS_DIR)/libmlx
LIBMLX_LINK = -L $(LIBMLX_DIR) -l $(patsubst lib%.a,%,$(LIBMLX_NAME))

LIBS =	$(LIBFT_NAME) \
				$(LIBMLX_NAME) \

SRCS = main.c
OBJS = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

BUILD_DIR = build

all: $(NAME)

$(NAME): $(OBJS) | $(LIBS)
	$(CC) $(CFLAGS) $^ $(LIBFT_LINK) $(LIBMLX_LINK) -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

%.a:
	@echo -n "Building $(CLR_YLW)$@$(CLR_STP)... "
	@$(MAKE) -C $(LIBS_DIR)/$(basename $@) > /dev/null 2>&1
	@echo "Done."

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	@$(MAKE) $@ -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) $@ -C $(LIBMLX_DIR) > /dev/null 2>&1

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) $@ -C $(LIBFT_DIR) > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re