/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 01:38:40 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/15 15:57:38 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_counter(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDCOUNT_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDCOUNT_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDCOUNT_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDCOUNT_FILEPATH);

	if (err)
		return (err);

	return (OK);
}