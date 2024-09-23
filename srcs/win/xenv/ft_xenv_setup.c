/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xenv_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:30:48 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 17:02:25 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_xenv_setup(t_xenv *x)
{
	x->window = NULL;
	x->display = mlx_init();

	if (!x->display)
		return (ERR_XSRV_INIT);
	return (OK);
}
