/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:22:23 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/27 14:09:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_error_print(t_error err)
{
	ft_putendl_fd("Error", STDERR_FILENO);

	if (err == ERR_BAD_ARGS)
		ft_putendl_fd("Invalid number of arguments", STDERR_FILENO);

	if (err == ERR_XSRV_INIT)
		ft_putendl_fd("Failed to connect to X Server", STDERR_FILENO);

	if (err == ERR_WIN_CREATE)
		ft_putendl_fd("Failed to create the game's window", STDERR_FILENO);

	if (err >= ERR_MAP_EXT && err <= ERR_MAP_PATH_ALLOC)
		ft_puterr_map(err);

	if (err >= ERR_XIMG_DATA && err <= ERR_XIMG_FILEPATH)
		ft_puterr_ximg(err);

	if (err >= ERR_RENDSCENE_DATA && err <= ERR_RENDSCENE_CREATE)
		ft_puterr_rendscene(err);

	if (err >= ERR_RENDBG_CREATE && err <= ERR_RENDBG_FILEPATH)
		ft_puterr_rendbg(err);
}
