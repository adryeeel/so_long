/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:13:01 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/06 01:13:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_exit(t_error err)
{
	ft_putendl_fd("Unable to render the game's exit point", STDERR_FILENO);

	if (err == ERR_RENDEXIT_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDEXIT_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDEXIT_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDEXIT_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}

