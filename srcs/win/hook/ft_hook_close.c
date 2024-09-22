/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:35:39 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/18 22:22:05 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int ft_hook_close(void *param)
{
	t_xenv *x;

	x = (t_xenv *)param;
	mlx_loop_end(x->display);
	return (0);
}
