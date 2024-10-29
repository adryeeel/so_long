/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:20:27 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/28 00:58:27 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_generate_type(char **message, char *err_type)
{
	char *join;

	if (ft_error_is(err_type, ERR_MAP))
		join = ft_strjoin(*message, "Invalid map ");

	if (ft_error_is(err_type, ERR_XSRV))
		join = ft_strjoin(*message, "X Environment");

	if (ft_error_is(err_type, ERR_REND))
		join = ft_strjoin(*message, "Unable to render ");

	if (ft_error_is(err_type, ERR_XIMG))
		join = ft_strjoin(*message, "Failed to create the X image");

	free(*message);
	*message = join;
}
