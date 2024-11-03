/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_goal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 04:53:09 by arocha-b          #+#    #+#             */
/*   Updated: 2024/11/01 04:56:52 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_mapc ft_bfs_goal(bool operation, t_mapc value)
{
	static t_mapc comp;

	if (operation == GET)
		return (comp);

	if (operation == SET)
		return (comp = value);

	return (UNKNOWN);
}