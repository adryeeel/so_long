/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_coll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:00:24 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 01:50:04 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_coll(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDCOLL_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDCOLL_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDCOLL_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDCOLL_FILEPATH);

	if (err)
		return (err);

	return (OK);
}
