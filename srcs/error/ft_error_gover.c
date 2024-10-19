/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_gover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:32:48 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/19 17:33:03 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_gover(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDGOVER_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDGOVER_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDGOVER_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDGOVER_FILEPATH);

	if (err)
		return (err);

	return (OK);
}
