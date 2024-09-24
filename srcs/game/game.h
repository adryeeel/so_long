/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:02:43 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/25 00:14:11 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "../map/map.h"
#include "../error/error.h"

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

/* Game — Avatar's Position */

void ft_move_up(t_game *game);
void ft_move_down(t_game *game);
void ft_move_left(t_game *game);
void ft_move_right(t_game *game);

#endif
