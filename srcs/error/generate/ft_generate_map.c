/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:05:46 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/29 19:32:47 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define MAP_READ	"read"
#define MAP_ALLOC	"alloc"

void ft_generate_map(char **message, char *err_cause)
{
	char *err_msg;

	if (ft_error_is(err_cause, MAP_READ))
		err_msg = ft_strdup("Failed to read map file");

	if (ft_error_is(err_cause, MAP_ALLOC))
		err_msg = ft_strdup("Failed to allocate map's grid");

	ft_generate_errno(&err_msg);

	free(*message);
	*message = err_msg;
}