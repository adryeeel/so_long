/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_multi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:49:15 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/28 00:29:51 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_generate_multi(char **message, char *phrase)
{
	char *msg;
	char *join_a;
	char *join_b;

	msg = ft_strmapi(phrase, ft_str_filter);
	join_a = ft_strjoin(msg, ".\n");
	join_b = ft_strjoin(*message, join_a);

	free(msg);
	free(join_a);
	free(*message);

	*message = join_b;
}