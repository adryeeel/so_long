/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:02:43 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 15:16:41 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "../error/error.h"

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

/* Game */

void ft_game_free(t_game game);
t_error ft_game_start(char *map_path);
t_error ft_game_setup(t_game *g, char *map_path);

/* Game — Map Manipulation */

t_error ft_map_process(t_map *map, char *map_path);

/* Game — Raw Map Manipulation */

void ft_cmap_free(char *raw_map[]);
char **ft_cmap_read(char *map_path);
t_error ft_cmap_isrect(char *raw_map[]);
int **ft_cmap_matrix(char *raw_map[]);
bool ft_cmap_push(char **map[], char *line);

/* Game — Enum Map Manipulation */

t_error ft_emap_check(t_map *map);
t_mapc ft_emap_component(char comp);
t_error ft_emap_setup(t_map *map, char *raw_map[]);

/* Game — Map Matrix Manipulation */

void ft_matrix_free(int **matrix);
int **ft_matrix_alloc(size_t x, size_t y);

/* Game — Avatar's Position */

void ft_move_up(t_game *game);
void ft_move_down(t_game *game);
void ft_move_left(t_game *game);
void ft_move_right(t_game *game);

#endif
