/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xenv_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:04:50 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 17:17:23 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_xenv_free(t_xenv x)
{
	if (x.display && x.window)
		mlx_destroy_window(x.display, x.window);

	if (x.display)
	{
		mlx_destroy_display(x.display);
		free(x.display);
	}
}
