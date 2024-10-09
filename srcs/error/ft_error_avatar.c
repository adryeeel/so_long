/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_avatar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:29:49 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 14:40:27 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_avatar(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDAVATAR_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDAVATAR_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDAVATAR_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDAVATAR_FILEPATH);

	if (err)
		return (err);

	return (OK);
}

