/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:48:22 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 14:39:07 by arocha-b         ###   ########.fr       */
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
#define TOTAL_DIRECTIONS 4

#define BG_IMG_PATH "assets/imgs/bg.xpm"
#define WALL_IMG_PATH "assets/imgs/wall.xpm"
#define AVATAR_IMG_PATH "assets/imgs/avatar.xpm"
#define COLL_IMG_PATH "assets/imgs/collectible.xpm"

/* Miscellaneous */

int **ft_dirs_setup(void);
void ft_matrix_free(int **matrix);
void ft_points_free(t_queue points);
int **ft_matrix_alloc(size_t x, size_t y);

#endif
