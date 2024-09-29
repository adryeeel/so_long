/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:29:49 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 18:31:02 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_wall(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDWALL_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDWALL_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDWALL_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDWALL_FILEPATH);

	if (err)
		return (err);

	return (OK);
}

