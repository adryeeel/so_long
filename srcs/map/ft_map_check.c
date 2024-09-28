/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:03:21 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/28 13:24:14 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_map_check(t_map map)
{
	t_error err;

	if (!ft_check_isrect(map))
		return (ERR_MAP_RECT);

	if (!ft_check_isreg(map))
		return (ERR_MAP_REG);

	if (!ft_check_surronded(map))
		return (ERR_MAP_SURRONDED);

	err = ft_check_format(map);
	if (err)
		return (err);

	err = ft_check_path(map);
	if (err)
		return (err);

	return (OK);
}