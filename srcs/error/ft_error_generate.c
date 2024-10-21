/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_generate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:57:12 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/21 19:07:59 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool ft_strarr_init(t_error err, t_strarr *strings)
{
	strings->data = ft_split(err, '_');

	if (!strings->data)
		return (false);

	strings->length = ft_strarr_length(strings->data);
	return (true);
}

static void ft_error_render(t_strarr strings)
{
	// Unable to render game's [word]
	//
}

void ft_error_generate(t_error err)
{
	t_strarr strings;

	if (!ft_strarr_init(err, &strings))
		return;
}