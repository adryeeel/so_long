/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:48:22 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 21:56:58 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdbool.h>

#include "../libs/libmlx/mlx.h"
#include "../libs/libft/libft.h"

typedef struct s_xenv
{
	void *window;
	void *display;
} t_xenv;

/* Window Management */

bool ft_win_setup(t_xenv x, t_game g);
int mlx_close_hook(void *win_ptr, int (*funct)(), void *param);

/* Window Management — Hooks */

int ft_hook_close(void *param);
int ft_hook_key(int key, void *param);

#endif
