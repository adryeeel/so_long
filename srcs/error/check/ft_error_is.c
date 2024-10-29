/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_is.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:12:46 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/29 19:14:24 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool ft_error_is(t_error err_a, t_error err_b)
{
	if (!err_a && !err_b)
		return (true);

	if (!err_a && err_b)
		return (false);

	if (!err_b && err_a)
		return (false);

	return (ft_strncmp(err_a, err_b, ft_strlen(err_a)) == 0);
}