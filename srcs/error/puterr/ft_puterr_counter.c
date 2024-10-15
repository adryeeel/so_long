/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:39:56 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/15 15:57:19 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_counter(t_error err)
{
	ft_putendl_fd("Unable to render the move counter", STDERR_FILENO);

	if (err == ERR_RENDCOUNT_PARAM)
		ft_puterr_ximg(ERR_XIMG_PARAM);

	if (err == ERR_RENDCOUNT_CREATE)
		ft_puterr_ximg(ERR_XIMG_CREATE);

	if (err == ERR_RENDCOUNT_DATA)
		ft_puterr_ximg(ERR_XIMG_DATA);

	if (err == ERR_RENDCOUNT_FILEPATH)
		ft_puterr_ximg(ERR_XIMG_FILEPATH);
}