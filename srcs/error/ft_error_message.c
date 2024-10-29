/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:57:12 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/25 13:47:40 by arocha-b         ###   ########.fr       */
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

char *ft_error_message(t_error err)
{
	char *message;
	t_strarr keywords;

	if (!err)
		return (NULL);

	if (!ft_strarr_init(err, &keywords))
		return (NULL);

	message = ft_error_generate(keywords);
	if (!message)
		return (NULL);

	ft_strarr_free(keywords);
	return (message);
}