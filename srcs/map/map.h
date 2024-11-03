/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 00:08:36 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/01 04:57:10 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdbool.h>

#define SET 0
#define GET 1

typedef char *t_error;

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

/* Map Validation */

bool ft_check_won(t_map map);
bool ft_check_isreg(t_map map);
bool ft_check_isrect(t_map map);
t_error ft_check_path(t_map map);
t_error ft_check_comp(t_map map);
bool ft_check_surrounded(t_map map);
t_error ft_check_ext(char *map_path);

/* Map Manipulation */

void ft_map_free(char *grid[]);
void ft_map_restart(t_map *map);
bool ft_map_iscomp(t_mapc comp);
void ft_map_setup(t_map *map, char *grid[]);
bool ft_map_push(char **grid[], char *line);

t_error ft_map_check(t_map map);
t_coord ft_map_search_seq(t_map map, t_mapc comp);
t_error ft_map_read(char **grid[], char *map_path);
t_error ft_map_process(t_map *map, char *map_path);
t_coord ft_map_search(t_map map, t_mapc comp, t_coord start);

/* Map BFS Algorithm  */

void ft_points_free(t_queue points, t_coord *pos);
t_error ft_points_setup(t_coord start, t_queue *points);

void ft_visited_free(int **visited);
t_error ft_visited_setup(t_map map, t_coord start, int ***visited);

bool ft_bfs_isgoal(t_coord curr, t_coord goal);
bool ft_bfs_isvalid(t_map map, t_coord pos, int **visited);

t_mapc ft_bfs_goal(bool operation, t_mapc value);
void ft_bfs_cleanup(t_queue points, int **visited);
t_error ft_bfs_path(t_map map, t_coord start, t_coord end);
t_error ft_visited_setup(t_map map, t_coord start, int ***visited);
t_error ft_bfs_edges(t_map map, t_queue *q, t_coord curr, int **visited);
t_error ft_bfs_process(t_map map, t_coord end, t_queue *points, int **visited);
t_error ft_bfs_setup(t_map map, t_coord start, t_queue *points, int ***visited);

#endif
