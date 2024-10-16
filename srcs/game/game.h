/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:02:43 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/15 13:48:04 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

typedef struct s_map t_map;
typedef enum e_error t_error;

#define LEFT 1
#define RIGHT 0

typedef struct s_avatar
{
	int x;
	int y;
	bool died;
	bool orient;
} t_avatar;

typedef struct s_game
{
	t_map map;
	size_t moves;
	t_avatar avatar;
} t_game;

/* Game */

void ft_game_free(t_game game);
t_error ft_game_start(char *map_path);
t_error ft_game_setup(t_game *g, char *map_path);

/* Game — Avatar's Movement */

void ft_move_up(t_game *game);
void ft_move_down(t_game *game);
void ft_move_left(t_game *game);
void ft_move_right(t_game *game);

#endif
