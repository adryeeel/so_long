/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:00:24 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/13 00:13:43 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_death(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDEATH_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDEATH_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDEATH_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDEATH_FILEPATH);

	if (err)
		return (err);

	return (OK);
}
