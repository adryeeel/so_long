/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_cause.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:19:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/29 19:16:54 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_generate_cause(char **message, char *err_cause)
{
	if (ft_strchr(err_cause, '-'))
		return (ft_generate_multi(message, err_cause), (void)0);

	if (ft_error_is_ximg(err_cause))
		ft_generate_ximg(message, err_cause);

	if (ft_error_is_map(err_cause))
		ft_generate_map(message, err_cause);
}
