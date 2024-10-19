/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:50:07 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 17:16:34 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define XK_LATIN1
#define XK_MISCELLANY

#include <X11/keysymdef.h>

void ft_key_exit(t_xenv x, int key)
{
	if (key == XK_Escape)
		mlx_loop_end(x.display);
}