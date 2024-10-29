/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_errno.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:48:35 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/28 02:55:46 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../so_long.h"

void ft_generate_errno(char **message)
{
	char *join_a;
	char *join_b;
	char *join_c;
	char *strerr;

	strerr = strerror(errno);
	join_a = ft_strjoin(strerr, ".\n");
	join_b = ft_strjoin(*message, ": ");
	join_c = ft_strjoin(join_b, join_a);

	free(join_a);
	free(join_b);
	free(*message);

	*message = join_c;
}