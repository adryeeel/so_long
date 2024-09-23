/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transl_rendscene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:57:06 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 20:13:06 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_error ft_transl_rendscene(t_error err)
{
	if (err == ERR_XIMG_CREATE)
		return (ERR_RENDSCENE_CREATE);

	if (err == ERR_XIMG_DATA)
		return (ERR_RENDSCENE_DATA);

	return (OK);
}

