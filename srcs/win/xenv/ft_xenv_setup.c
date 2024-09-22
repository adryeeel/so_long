/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xenv_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:30:48 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 15:30:18 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_xenv_setup(t_xenv *x)
{
	x->window = NULL;
	x->display = mlx_init();

	if (!x->display)
		return (false);
	return (true);
}
