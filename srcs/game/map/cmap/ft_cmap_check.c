/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmap_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:03:21 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/24 15:22:55 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

t_error ft_cmap_check(char *raw_map[])
{
	if (!ft_check_isrect(raw_map))
		return (ERR_MAP_RECT);

	if (!ft_check_isreg(raw_map))
		return (ERR_MAP_REG);

	return (OK);
}
