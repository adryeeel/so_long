/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_avatar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:32:28 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 14:41:31 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_avatar(t_error err)
{
	ft_putendl_fd("Unable to render game's avatar", STDERR_FILENO);

	if (err == ERR_RENDAVATAR_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDAVATAR_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDAVATAR_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDAVATAR_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}
