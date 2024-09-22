/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:48:22 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 00:10:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdbool.h>

#include "../libs/libmlx/mlx.h"
#include "../libs/libft/libft.h"

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

#endif
