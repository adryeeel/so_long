/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:17:06 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 17:15:33 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int ft_hook_key(int key, void *param)
{
	t_xenv *x;
	t_game *g;

	x = ((t_param *)param)->x;
	g = ((t_param *)param)->g;
	
	if (x->allow_move)
	{
		ft_key_move(*x, g, key);
		return (0);
	}

	ft_key_exit(*x, key);
	return (0);
}
