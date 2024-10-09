/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_patrol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:02:49 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/09 22:20:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_patrol(t_error err)
{
	ft_putendl_fd("Unable to render the game's enemies' patrol", STDERR_FILENO);

	if (err == ERR_RENDPATROL_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDPATROL_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDPATROL_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDPATROL_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}
