/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_emap_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:43:34 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/25 00:15:12 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// A valid
// Valid componenets
// One exit, one start and at least one collectible
// Must be surrounded by walls

t_flags ft_parse_flags(t_map map)
{
	t_flags flags;

	flags.exit = 0;
	flags.start = 0;
	flags.unknown = 0;
	flags.collectible = 0;

	(void)map;
	return (flags);
}

t_error ft_emap_check(t_map map)
{
	(void)map;
	return (OK);
}
