/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr_ximg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:32:07 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/25 02:31:39 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_puterr_ximg(t_error err)
{
	if (err == ERR_XIMG_DATA)
		ft_putendl_fd("Failed to create the X image: Faulty image buffer", STDERR_FILENO);

	if (err == ERR_XIMG_PARAM)
		ft_putendl_fd("Failed to create the X image: Invalid parameters", STDERR_FILENO);

	if (err == ERR_XIMG_CREATE)
		ft_putendl_fd("Failed to create the X image", STDERR_FILENO);

	if (err == ERR_XIMG_FILEPATH)
		perror("Failed to create the X image with XPM file");
}
