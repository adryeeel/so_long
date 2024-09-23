/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:48:22 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 01:56:12 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdbool.h>

#include "../libs/libmlx/mlx.h"
#include "../libs/libft/libft.h"

#define TILE_SIZE 32
#define BG_IMG_PATH "assets/imgs/wall.xpm"
#define AVATAR_IMG_PATH "assets/imgs/avatar.xpm"

typedef enum e_mapc
{
	WALL,
	SPACE,
	EXIT_POINT,
	START_POINT,
	COLLECTIBLE,
	UNKNOWN,
} t_mapc;

typedef struct s_map
{
	int **matrix;
	size_t width;
	size_t height;
} t_map;

typedef struct s_coord
{
	int x;
	int y;
} t_coord;

typedef struct s_game
{
	t_map map;
	t_coord avatar;
} t_game;

typedef struct s_xenv
{
	void *window;
	void *display;
} t_xenv;

typedef struct s_ximg
{
	int bpp;
	int endian;
	int size_line;
	int width;
	int height;

	void *id;
	char *buff;
	char *path;
} t_ximg;

typedef struct s_param
{
	t_xenv *x;
	t_game *g;
} t_param;

/* Window Management */

bool ft_win_setup(t_xenv x, t_game g);
int mlx_close_hook(void *win_ptr, int (*funct)(), void *param);

/* Window Management — Hooks */

int ft_hook_close(void *param);
int ft_hook_key(int key, void *param);

/* Window Management — Rendering */

bool ft_render_bg(void *display, t_ximg *scene);
bool ft_render_scene(t_xenv x, t_game g, t_ximg *scene);

/* Window Management — Xenv */

void ft_xenv_free(t_xenv x);
bool ft_xenv_setup(t_xenv *x);

/* Window Management — Ximg */

void ft_ximg_free(void *display, t_ximg ximg);
bool ft_ximgf_setup(void *display, t_ximg *ximg, char *path);
bool ft_ximg_setup(void *display, t_ximg *ximg, int width, int height);

/* Game */

void ft_game_free(t_game game);
bool ft_game_start(char *map_path);
bool ft_game_setup(t_game *g, char *map_path);

/* Game — Map Manipulation */

bool ft_map_process(t_map *map, char *map_path);

/* Game — Raw Map Manipulation */

void ft_cmap_free(char *raw_map[]);
char **ft_cmap_read(char *map_path);
bool ft_cmap_isrect(char *raw_map[]);
int **ft_cmap_matrix(char *raw_map[]);
bool ft_cmap_push(char **map[], char *line);

/* Game — Enum Map Manipulation */

bool ft_emap_check(t_map *map);
t_mapc ft_emap_component(char comp);
bool ft_emap_setup(t_map *map, char *raw_map[]);

/* Game — Avatar's Position */

void ft_move_up(t_game *game);
void ft_move_down(t_game *game);
void ft_move_left(t_game *game);
void ft_move_right(t_game *game);

#endif
