/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_what.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:20:24 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/28 00:48:47 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void ft_generate_single(char **message, char *err_what)
{
	char *join;

	join = ft_strjoin(*message, err_what);
	free(*message);
	*message = join;
}

void ft_generate_what(char **message, char *err_what)
{
	if (ft_strchr(err_what, '-'))
		return (ft_generate_multi(message, err_what), (void)0);

	ft_generate_single(message, err_what);
}