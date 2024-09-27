/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:08:36 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/27 15:32:59 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

typedef enum e_error t_error;

typedef struct s_coord
{
	int x;
	int y;
} t_coord;

typedef enum e_mapc
{
	WALL,
	SPACE,
	EXIT_POINT,
	START_POINT,
	COLLECTIBLE,
	UNKNOWN,
} t_mapc;

typedef struct s_flags
{
	int exit;
	int start;
	int unknown;
	int collectible;
} t_flags;

typedef struct s_map
{
	int **matrix;
	size_t width;
	size_t height;
} t_map;

/* Game — Map Manipulation */

t_error ft_map_process(t_map *map, char *map_path);

/* Game — Map Validation */

t_error ft_check_path(t_map map);
bool ft_check_surronded(t_map map);
t_error ft_check_ext(char *map_path);
bool ft_check_isreg(char *raw_map[]);
bool ft_check_isrect(char *raw_map[]);

/* Game — Raw Map Manipulation */

void ft_cmap_free(char *raw_map[]);
int **ft_cmap_matrix(char *raw_map[]);
t_error ft_cmap_check(char *raw_map[]);
bool ft_cmap_push(char **raw_map[], char *line);
t_error ft_cmap_read(char **raw_map[], char *map_path);

/* Game — Enum Map Manipulation */

t_error ft_emap_check(t_map map);
t_mapc ft_emap_component(char comp);
t_coord ft_emap_search(t_map map, t_mapc comp);
t_error ft_emap_setup(t_map *map, char *raw_map[]);
t_error ft_emap_bfs(t_map map, t_coord start, t_coord end);

#endif
