/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 02:13:33 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/07 01:10:00 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_game_start(char *map_path)
{
	t_xenv x;
	t_game g;
	t_error err;
	t_param args;

	err = ft_game_setup(&g, map_path);
	if (err)
		return (err);

	err = ft_xenv_setup(&x, g.map);
	if (err)
	{
		ft_game_free(g);
		return (err);
	}

	args.x = &x;
	args.g = &g;

	err = ft_win_setup(&x, g, &args);
	if (err)
	{
		ft_xenv_free(x);
		ft_game_free(g);
		return (err);
	}

	mlx_loop(x.display);

	ft_xenv_free(x);
	ft_game_free(g);

	return (OK);
}
