/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:32:28 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 20:56:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_wall(t_error err)
{
	ft_putendl_fd("Unable to render map walls", STDERR_FILENO);

	if (err == ERR_RENDWALL_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDWALL_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDWALL_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDWALL_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}
