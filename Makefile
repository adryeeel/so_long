NAME = so_long

CLR_YLW = \033[0;33m
CLR_STP = \033[m

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

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

# Error handling sources

ERROR = ft_error_print.c \

ERROR_PATH = $(MAIN_PATH)/error
ERROR_OBJS = $(addprefix $(BUILD_DIR)/,$(ERROR:.c=.o))

# Error print sources

ERRORP =	ft_puterr_map.c \
			ft_puterr_ximg.c \
			ft_puterr_rendbg.c \
			ft_puterr_rendscene.c \

ERRORP_PATH = $(ERROR_PATH)/puterr
ERRORP_OBJS = $(addprefix $(BUILD_DIR)/,$(ERRORP:.c=.o))

# Error translate sources

ERRORT =	ft_transl_rendbg.c \
			ft_transl_rendscene.c \

ERRORT_PATH = $(ERROR_PATH)/translate
ERRORT_OBJS = $(addprefix $(BUILD_DIR)/,$(ERRORT:.c=.o))

# Window Management sources

WIN =	ft_win_setup.c \
		mlx_close_hook.c \

WIN_PATH = $(MAIN_PATH)/win
WIN_OBJS = $(addprefix $(BUILD_DIR)/,$(WIN:.c=.o))

# Window Management — Hook sources

HOOK =	ft_hook_key.c \
		ft_hook_close.c \

HOOK_PATH = $(WIN_PATH)/hook
HOOK_OBJS = $(addprefix $(BUILD_DIR)/,$(HOOK:.c=.o))

# Window Management — Render sources

RENDER =	ft_render_bg.c \
			ft_render_scene.c \

RENDER_PATH = $(WIN_PATH)/render
RENDER_OBJS = $(addprefix $(BUILD_DIR)/,$(RENDER:.c=.o))

# Window Management — Xenv sources

XENV =	ft_xenv_free.c \
		ft_xenv_setup.c \

XENV_PATH = $(WIN_PATH)/xenv
XENV_OBJS = $(addprefix $(BUILD_DIR)/,$(XENV:.c=.o))

# Window Management — Ximg sources

XIMG =	ft_ximg_free.c \
		ft_ximg_setup.c \
		ft_ximgf_setup.c \

XIMG_PATH = $(WIN_PATH)/ximg
XIMG_OBJS = $(addprefix $(BUILD_DIR)/,$(XIMG:.c=.o))

# Game sources

GAME =	ft_game_free.c \
		ft_game_start.c \
		ft_game_setup.c \

GAME_PATH = $(MAIN_PATH)/game
GAME_OBJS = $(addprefix $(BUILD_DIR)/,$(GAME:.c=.o))

# Game — Movement sources

MOVE =	ft_move_up.c \
		ft_move_down.c \
		ft_move_left.c \
		ft_move_right.c \

MOVE_PATH = $(GAME_PATH)/move
MOVE_OBJS = $(addprefix $(BUILD_DIR)/,$(MOVE:.c=.o))

# Game — Map handling sources

MAP =	ft_map_bfs.c \
		ft_map_free.c \
		ft_map_push.c \
		ft_map_read.c \
		ft_map_check.c \
		ft_map_setup.c \
		ft_map_search.c \
		ft_map_process.c \

MAP_PATH = $(MAIN_PATH)/map
MAP_OBJS = $(addprefix $(BUILD_DIR)/,$(MAP:.c=.o))

# Game — Map validation sources

MAPC =	ft_check_ext.c \
		ft_check_path.c \
		ft_check_isreg.c \
		ft_check_format.c \
		ft_check_isrect.c \
		ft_check_surronded.c \

MAPC_PATH = $(MAP_PATH)/check
MAPC_OBJS = $(addprefix $(BUILD_DIR)/,$(MAPC:.c=.o))

# Matrix sources

MATRIX =	ft_matrix_free.c \
			ft_matrix_alloc.c \

MATRIX_PATH = $(MAIN_PATH)/matrix
MATRIX_OBJS = $(addprefix $(BUILD_DIR)/,$(MATRIX:.c=.o))

# Miscellaneous sources

MISC =	ft_dirs_setup.c \
		ft_points_free.c \

MISC_PATH = $(MAIN_PATH)/misc
MISC_OBJS = $(addprefix $(BUILD_DIR)/,$(MISC:.c=.o))

# Build Rules

all: $(NAME)

# Program Build

$(NAME): $(MAIN_OBJS) $(ERROR_OBJS) $(ERRORP_OBJS) $(ERRORT_OBJS)  $(WIN_OBJS) $(HOOK_OBJS) $(RENDER_OBJS) $(XENV_OBJS) $(XIMG_OBJS) $(GAME_OBJS) $(MOVE_OBJS) $(MAP_OBJS) $(MAPC_OBJS) $(MATRIX_OBJS) $(MISC_OBJS) | $(LIBS)
	$(CC) $(CFLAGS) $^ $(LIBS_LINK) -o $@

# Main Build

$(BUILD_DIR)/%.o: $(MAIN_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Error handling build

$(BUILD_DIR)/%.o: $(ERROR_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(ERRORP_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(ERRORT_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Window Management Build

$(BUILD_DIR)/%.o: $(WIN_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(HOOK_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(RENDER_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(XENV_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(XIMG_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Game Build

$(BUILD_DIR)/%.o: $(GAME_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(MOVE_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(MAP_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(MAPC_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Helpers Build

$(BUILD_DIR)/%.o: $(MISC_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(MATRIX_PATH)/%.c | $(BUILD_DIR)
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