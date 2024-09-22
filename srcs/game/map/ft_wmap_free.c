/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmap_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 04:59:37 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/20 23:40:27 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_wmap_free(char *raw_map[])
{
	size_t i;

	i = 0;
	while (raw_map[i])
	{
		free(raw_map[i]);
		i++;
	}
	free(raw_map);
}
