/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:02:49 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/13 00:15:35 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_death(t_error err)
{
	ft_putendl_fd("Unable to render avatar's death animation", STDERR_FILENO);

	if (err == ERR_RENDEATH_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDEATH_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDEATH_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDEATH_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}
