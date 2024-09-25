/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emap_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:43:34 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/25 02:13:35 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_flags ft_flags_setup(void)
{
	t_flags flags;

	flags.exit = 0;
	flags.start = 0;
	flags.unknown = 0;
	flags.collectible = 0;

	return (flags);
}

t_flags ft_flags_parse(t_map map)
{
	int *row;
	size_t i;
	size_t j;
	t_flags flags;

	i = 1;
	row = map.matrix[0];
	flags = ft_flags_setup();

	while (row)
	{
		j = 0;
		while (row[j] != -1)
		{
			if (row[j] == EXIT_POINT)
				flags.exit++;

			if (row[j] == START_POINT)
				flags.start++;

			if (row[j] == COLLECTIBLE)
				flags.collectible++;

			if (row[j] == UNKNOWN)
				flags.unknown++;

			j++;
		}
		row = map.matrix[i++];
	}

	return (flags);
}

t_error ft_emap_check(t_map map)
{
	t_flags flags;

	flags = ft_flags_parse(map);

	if (!ft_check_surronded(map))
		return (ERR_MAP_SURRONDED);

	if (flags.exit != 1)
		return (ERR_MAP_EXIT);

	if (flags.start != 1)
		return (ERR_MAP_START);

	if (flags.unknown)
		return (ERR_MAP_UNKNOWN);

	if (!flags.collectible)
		return (ERR_MAP_COLLECTIBLE);

	return (OK);
}
