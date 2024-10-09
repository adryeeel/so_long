/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_iscomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 23:50:27 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/07 23:52:55 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool ft_map_iscomp(t_mapc comp)
{
	if (comp == WALL)
		return (true);

	if (comp == SPACE)
		return (true);

	if (comp == PATROL)
		return (true);

	if (comp == COLLECTIBLE)
		return (true);

	if (comp == START_POINT)
		return (true);

	if (comp == EXIT_POINT)
		return (true);

	return (false);
}
