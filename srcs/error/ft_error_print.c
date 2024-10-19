/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:22:23 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 18:16:03 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_error_print(t_error err)
{
	ft_putendl_fd("Error", STDERR_FILENO);

	if (err == ERR_BAD_ARGS)
		ft_putendl_fd("Invalid number of arguments", STDERR_FILENO);

	if (err == ERR_XSRV_INIT)
		ft_putendl_fd("Failed to connect to the X Server", STDERR_FILENO);

	if (err == ERR_WIN_CREATE)
		ft_putendl_fd("Failed to create the game's window", STDERR_FILENO);

	if (err >= ERR_MAP_EXT && err <= ERR_MAP_PATH_ALLOC)
		ft_puterr_map(err);

	if (err >= ERR_XIMG_DATA && err <= ERR_XIMG_FILEPATH)
		ft_puterr_ximg(err);

	if (err >= ERR_RENDSCENE_DATA && err <= ERR_RENDSCENE_CREATE)
		ft_puterr_scene(err);

	if (err >= ERR_RENDPATROL_DATA && err <= ERR_RENDPATROL_FILEPATH)
		ft_puterr_patrol(err);

	if (err >= ERR_RENDAVATAR_DATA && err <= ERR_RENDAVATAR_FILEPATH)
		ft_puterr_avatar(err);

	if (err >= ERR_RENDBG_DATA && err <= ERR_RENDBG_FILEPATH)
		ft_puterr_space(err);

	if (err >= ERR_RENDWALL_DATA && err <= ERR_RENDWALL_FILEPATH)
		ft_puterr_wall(err);

	if (err >= ERR_RENDCOLL_DATA && err <= ERR_RENDCOLL_FILEPATH)
		ft_puterr_coll(err);

	if (err >= ERR_RENDEXIT_DATA && err <= ERR_RENDEXIT_FILEPATH)
		ft_puterr_exit(err);

	if (err >= ERR_RENDEATH_DATA && err <= ERR_RENDEATH_FILEPATH)
		ft_puterr_death(err);

	if (err >= ERR_RENDCOUNT_DATA && err <= ERR_RENDCOUNT_FILEPATH)
		ft_puterr_counter(err);

	if (err >= ERR_RENDGOVER_DATA && err <= ERR_RENDGOVER_FILEPATH)
		ft_puterr_gover(err);
}

/** 
 * ! Refactor this code to string-based errors: "render/gover/filepath"
 * ! Implement a t_error for const char *
 * ! Refactor enum to strings macros
 * ! Or just give up from so many error cases :/
*/

