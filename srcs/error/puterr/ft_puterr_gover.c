/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_gover.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:33:45 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 17:34:21 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_gover(t_error err)
{
	ft_putendl_fd("Unable to render the game over screen", STDERR_FILENO);

	if (err == ERR_RENDGOVER_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDGOVER_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDGOVER_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDGOVER_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}
