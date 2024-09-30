/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_coll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:02:49 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 01:50:07 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_coll(t_error err)
{
	ft_putendl_fd("Unable to render map collectible(s)", STDERR_FILENO);

	if (err == ERR_RENDCOLL_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDCOLL_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDCOLL_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDCOLL_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}
