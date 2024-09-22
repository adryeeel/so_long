/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 02:13:33 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/22 15:50:48 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool ft_game_start(char *map_path)
{
	t_xenv x;
	t_game game;

	if (!ft_xenv_setup(&x))
		return (false);

	if (!ft_game_setup(&game, map_path))
	{
		ft_xenv_free(x);
		return (false);
	}

	if (!ft_win_setup(x, game))
	{
		ft_xenv_free(x);
		ft_game_free(game);
		return (false);
	}

	return (true);
}
