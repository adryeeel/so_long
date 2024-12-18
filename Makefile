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
LIBS_LINK = $(LIBFT_LINK) $(LIBMLX_LINK) -l Xext -l X11 -l m

# Main Sources

MAIN = so_long.c \

MAIN_PATH = srcs
MAIN_OBJS = $(addprefix $(BUILD_DIR)/,$(MAIN:.c=.o))

# Error handling sources

ERROR =	ft_error.c \
		ft_error_is.c \
		ft_error_free.c \
		ft_error_print.c \
		ft_error_message.c \
		ft_error_generate.c \

ERROR_PATH = $(MAIN_PATH)/error
ERROR_OBJS = $(addprefix $(BUILD_DIR)/,$(ERROR:.c=.o))

# Error Generator sources

EGEN =	ft_generate_map.c \
		ft_generate_type.c \
		ft_generate_what.c \
		ft_generate_ximg.c \
		ft_generate_multi.c \
		ft_generate_errno.c \
		ft_generate_cause.c \

EGEN_PATH = $(ERROR_PATH)/generate
EGEN_OBJS = $(addprefix $(BUILD_DIR)/,$(EGEN:.c=.o))

# Error Checking Sources

ECHECK =	ft_error_is.c \
			ft_error_is_map.c \
			ft_error_is_ximg.c \

ECHECK_PATH = $(ERROR_PATH)/check
ECHECK_OBJS = $(addprefix $(BUILD_DIR)/,$(ECHECK:.c=.o))

# Window Management sources

WIN =	ft_win_draw.c \
		ft_win_setup.c \
		mlx_close_hook.c \

WIN_PATH = $(MAIN_PATH)/win
WIN_OBJS = $(addprefix $(BUILD_DIR)/,$(WIN:.c=.o))

# Window Management — Hook sources

HOOK =	ft_hook_key.c \
		ft_hook_loop.c \
		ft_hook_close.c \

HOOK_PATH = $(WIN_PATH)/hook
HOOK_OBJS = $(addprefix $(BUILD_DIR)/,$(HOOK:.c=.o))

# Window Management — Key sources

KEY =	ft_key_exit.c \
		ft_key_move.c \

KEY_PATH = $(WIN_PATH)/key
KEY_OBJS = $(addprefix $(BUILD_DIR)/,$(KEY:.c=.o))

# Window Management — Render sources

DRAW =	ft_draw_at.c \
		ft_draw_anim.c \
		ft_draw_comp.c \
		ft_draw_move.c \
		ft_draw_frame.c \
		ft_draw_death.c \
		ft_draw_final.c \
		ft_draw_counter.c \
		ft_draw_fadeout.c \
		ft_draw_background.c \

DRAW_PATH = $(WIN_PATH)/draw
DRAW_OBJS = $(addprefix $(BUILD_DIR)/,$(DRAW:.c=.o))

# Window Management — Xenv sources

XENV =	ft_xenv_free.c \
		ft_xenv_setup.c \

XENV_PATH = $(WIN_PATH)/xenv
XENV_OBJS = $(addprefix $(BUILD_DIR)/,$(XENV:.c=.o))

# Window Management — Ximg sources

XIMG =	ft_ximg_free.c \
		ft_ximg_copy.c \
		ft_ximg_setup.c \
		ft_ximg_frame.c \
		ft_ximgf_setup.c \
		ft_ximg_sprite.c \
		ft_ximg_fill_alpha.c \

XIMG_PATH = $(WIN_PATH)/ximg
XIMG_OBJS = $(addprefix $(BUILD_DIR)/,$(XIMG:.c=.o))

# Game sources

GAME =	ft_game_free.c \
		ft_game_start.c \
		ft_game_setup.c \
		ft_game_restart.c \

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

MAP =	ft_map_free.c \
		ft_map_push.c \
		ft_map_read.c \
		ft_map_check.c \
		ft_map_setup.c \
		ft_map_search.c \
		ft_map_iscomp.c \
		ft_map_process.c \
		ft_map_restart.c \
		ft_map_search_seq.c \

MAP_PATH = $(MAIN_PATH)/map
MAP_OBJS = $(addprefix $(BUILD_DIR)/,$(MAP:.c=.o))

# Game — Map validation sources

MAPC =	ft_check_ext.c \
		ft_check_won.c \
		ft_check_path.c \
		ft_check_comp.c \
		ft_check_isreg.c \
		ft_check_isrect.c \
		ft_check_isempty.c \
		ft_check_surrounded.c \

MAPC_PATH = $(MAP_PATH)/check
MAPC_OBJS = $(addprefix $(BUILD_DIR)/,$(MAPC:.c=.o))

# Game — Map pathway validation sources

MAPBFS =	ft_bfs_path.c \
			ft_bfs_goal.c \
			ft_bfs_edges.c \
			ft_bfs_setup.c \
			ft_bfs_isgoal.c \
			ft_bfs_cleanup.c \
			ft_bfs_process.c \
			ft_points_free.c \
			ft_bfs_isvalid.c \
			ft_visited_free.c \
			ft_points_setup.c \
			ft_visited_setup.c \

MAPBFS_PATH = $(MAP_PATH)/bfs
MAPBFS_OBJS = $(addprefix $(BUILD_DIR)/,$(MAPBFS:.c=.o))

# Miscellaneous sources

MISC =	ft_dirs_setup.c \
		ft_str_filter.c \
		ft_points_free.c \
		ft_matrix_free.c \
		ft_matrix_alloc.c \
		ft_error_draw_final.c \

MISC_PATH = $(MAIN_PATH)/misc
MISC_OBJS = $(addprefix $(BUILD_DIR)/,$(MISC:.c=.o))

# Debug Make Flag
ifeq ($(debug), 1)
    CFLAGS += -g
endif

# Leak Make Flag
ifeq ($(leaks), 1)
    CFLAGS += -fsanitize=address
endif

# Build Rules

all: $(NAME)

# Program Build

$(NAME): $(MAIN_OBJS) $(ERROR_OBJS) $(EGEN_OBJS) $(ECHECK_OBJS) $(WIN_OBJS) $(HOOK_OBJS) $(KEY_OBJS) $(DRAW_OBJS) $(XENV_OBJS) $(XIMG_OBJS) $(GAME_OBJS) $(MOVE_OBJS) $(MAP_OBJS) $(MAPC_OBJS) $(MAPBFS_OBJS) $(MATRIX_OBJS) $(MISC_OBJS) | $(LIBS)
	$(CC) $(CFLAGS) $^ $(LIBS_LINK) -o $@

# Main Build

$(BUILD_DIR)/%.o: $(MAIN_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Error handling build

$(BUILD_DIR)/%.o: $(ERROR_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(EGEN_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(ECHECK_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Window Management Build

$(BUILD_DIR)/%.o: $(WIN_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(HOOK_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(KEY_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(DRAW_PATH)/%.c | $(BUILD_DIR)
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

$(BUILD_DIR)/%.o: $(MAPBFS_PATH)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Helper Functions Build

$(BUILD_DIR)/%.o: $(MISC_PATH)/%.c | $(BUILD_DIR)
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

debug:
	@$(MAKE) debug=1

leak:
	@$(MAKE) leaks=1

clean:
	rm -rf $(BUILD_DIR)
	@$(MAKE) $@ -C $(LIBFT_PATH) > /dev/null 2>&1
	@$(MAKE) $@ -C $(LIBMLX_PATH) > /dev/null 2>&1

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) $@ -C $(LIBFT_PATH) > /dev/null 2>&1
	@$(MAKE) $< -C $(LIBMLX_PATH) > /dev/null 2>&1

re: fclean all

.PHONY: debug leak all clean fclean re