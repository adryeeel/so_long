/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:51:04 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 00:20:56 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "../so_long.h"

int mlx_close_hook(void *win_ptr, int (*funct)(), void *param)
{
	mlx_hook(win_ptr, DestroyNotify, StructureNotifyMask, funct, param);
	return (0);
}
