/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_rendbg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:57:06 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 20:12:52 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_transl_rendbg(t_error err)
{
	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDBG_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDBG_DATA);

	if (err == ERR_XIMG_FILEPATH)
		return (ERR_RENDBG_FILEPATH);

	return (OK);
}
