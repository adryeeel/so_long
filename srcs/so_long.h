/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:48:22 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 13:23:33 by arocha-b         ###   ########.fr       */
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

#define TILE_SIZE 32
#define AVATAR START_POINT

#define EXIT_IMG_PATH "assets/imgs/exit.xpm"
#define WALL_IMG_PATH "assets/imgs/wall.xpm"
#define SPACE_IMG_PATH "assets/imgs/space.xpm"
#define MOVES_IMG_PATH "assets/imgs/moves.xpm"
#define PATROL_IMG_PATH "assets/imgs/patrol.xpm"
#define AVATAR_IMG_PATH "assets/imgs/avatar.xpm"
#define NUMBER_IMG_PATH "assets/imgs/number.xpm"
#define COLL_IMG_PATH "assets/imgs/collectible.xpm"
#define DEATH_IMG_PATH "assets/imgs/avatar-death.xpm"
#define LAVATAR_IMG_PATH "assets/imgs/avatar-left.xpm"

/* Miscellaneous */

int **ft_dirs_setup(void);
void ft_matrix_free(int **matrix);
void ft_points_free(t_queue points);
int **ft_matrix_alloc(size_t x, size_t y);

#endif
