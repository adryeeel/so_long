/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:30:02 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 16:55:31 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_scene(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDSCENE_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDSCENE_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDSCENE_DATA);

	if (err)
		return (err);

	return (OK);
}
