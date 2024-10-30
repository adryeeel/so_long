/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_is_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:18:33 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/29 19:19:31 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define MAP_READ	"read"
#define MAP_ALLOC	"alloc"

bool ft_error_is_map(char *err_cause)
{
	if (ft_error_is(err_cause, MAP_READ))
		return (true);

	if (ft_error_is(err_cause, MAP_ALLOC))
		return (true);

	return (false);
}
