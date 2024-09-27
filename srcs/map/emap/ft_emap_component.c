/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emap_component.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:48:45 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/24 22:40:24 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_mapc ft_emap_component(char comp)
{
	if (comp == '0')
		return (SPACE);

	if (comp == '1')
		return (WALL);

	if (comp == 'C')
		return (COLLECTIBLE);

	if (comp == 'E')
		return (EXIT_POINT);

	if (comp == 'P')
		return (START_POINT);

	return (UNKNOWN);
}
