/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:48:22 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/01 00:35:02 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libs/libmlx/mlx.h"
#include "../libs/libft/libft.h"

#include "error/error.h"
#include "map/map.h"
#include "game/game.h"
#include "win/win.h"

#define EXIT_IMG_PATH		"assets/imgs/exit.xpm"
#define WALL_IMG_PATH		"assets/imgs/wall.xpm"
#define SPACE_IMG_PATH		"assets/imgs/space.xpm"
#define MOVES_IMG_PATH		"assets/imgs/moves.xpm"
#define PATROL_IMG_PATH		"assets/imgs/patrol.xpm"
#define AVATAR_IMG_PATH		"assets/imgs/avatar.xpm"
#define NUMBER_IMG_PATH		"assets/imgs/number.xpm"
#define GWON_IMG_PATH		"assets/imgs/you-won.xpm"
#define GOVER_IMG_PATH		"assets/imgs/game-over.xpm"
#define COLL_IMG_PATH		"assets/imgs/collectible.xpm"
#define DEATH_IMG_PATH		"assets/imgs/avatar-death.xpm"
#define LAVATAR_IMG_PATH	"assets/imgs/avatar-left.xpm"

#define TILE_SIZE 32
#define AVATAR START_POINT
#define GAME_OVER GOVER_IMG_PATH
#define GAME_WON GWON_IMG_PATH

/* Miscellaneous */

int **ft_dirs_setup(void);
void ft_matrix_free(int **matrix);
int **ft_matrix_alloc(size_t x, size_t y);
char ft_str_filter(unsigned int index, char c);
t_error ft_error_draw_final(t_error err, char *text_path);

#endif
