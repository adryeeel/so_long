/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:30:04 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 16:55:22 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_bg(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDBG_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDBG_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDBG_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDBG_FILEPATH);

	if (err)
		return (err);

	return (OK);
}
