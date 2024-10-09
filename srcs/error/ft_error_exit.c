/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:11:46 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/06 01:12:16 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_exit(t_error err)
{
	if (err == ERR_XIMG_PARAM)
		return (ERR_RENDEXIT_PARAM);

	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDEXIT_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDEXIT_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDEXIT_FILEPATH);

	if (err)
		return (err);

	return (OK);
}
