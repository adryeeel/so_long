/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 02:13:33 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/29 20:24:36 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_game_start(char *map_path)
{
	t_xenv x;
	t_game game;
	t_error err;

	err = ft_game_setup(&game, map_path);
	if (err)
		return (err);
	
	err = ft_xenv_setup(&x, game.map);
	if (err)
	{
		ft_game_free(game);
		return (err);
	}

	err = ft_win_setup(&x, game);
	if (err)
	{
		ft_xenv_free(x);
		ft_game_free(game);
		return (err);
	}
	return (OK);
}
