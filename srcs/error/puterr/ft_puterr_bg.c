/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_bg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:32:07 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 16:28:38 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_bg(t_error err)
{
	ft_putendl_fd("Unable to render the game's background", STDERR_FILENO);

	if (err == ERR_RENDBG_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDBG_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDBG_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDBG_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}
