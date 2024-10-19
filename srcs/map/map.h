/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:08:36 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 17:18:03 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdbool.h>

typedef enum e_error t_error;

typedef struct s_coord
{
	int x;
	int y;
} t_coord;

typedef enum e_mapc
{
	UNKNOWN = 0,
	WALL = '1',
	SPACE = '0',
	PATROL = 'L',
	EXIT_POINT = 'E',
	START_POINT = 'P',
	COLLECTED = 'c',
	COLLECTIBLE = 'C',
} t_mapc;

typedef struct s_flags
{
	int exit;
	int start;
	int patrol;
	int unknown;
	int collectible;
} t_flags;

typedef struct s_map
{
	char **grid;
	size_t width;
	size_t height;
} t_map;

/* Game — Map Validation */

bool ft_check_isreg(t_map map);
bool ft_check_isrect(t_map map);
t_error ft_check_path(t_map map);
t_error ft_check_comp(t_map map);
bool ft_check_surrounded(t_map map);
t_error ft_check_ext(char *map_path);

/* Game — Map Manipulation */

void ft_map_free(char *grid[]);
bool ft_map_iscomp(t_mapc comp);
void ft_map_setup(t_map *map, char *grid[]);
bool ft_map_push(char **grid[], char *line);

void ft_map_restart(t_map *map);
t_error ft_map_check(t_map map);
t_coord ft_map_search_seq(t_map map, t_mapc comp);
t_error ft_map_read(char **grid[], char *map_path);
t_error ft_map_process(t_map *map, char *map_path);
t_error ft_map_bfs(t_map map, t_coord start, t_coord end);
t_coord ft_map_search(t_map map, t_mapc comp, t_coord start);

#endif
