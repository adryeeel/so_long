/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:32:07 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 16:26:24 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_scene(t_error err)
{
	ft_putendl_fd("Unable to render the game's scene", STDERR_FILENO);

	if (err == ERR_RENDSCENE_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDSCENE_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDSCENE_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);
}
