/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_generate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 01:10:34 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/28 02:22:31 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *ft_error_generate(t_strarr keywords)
{
	char *message;
	char *err_type;
	char *err_what;
	char *err_cause;

	message = ft_calloc(NULL_BYTE, sizeof(char));
	if (!message)
		return (NULL);

	err_type = keywords.data[0];
	err_what = keywords.data[1];

	ft_generate_type(&message, err_type);
	ft_generate_what(&message, err_what);

	if (keywords.length > 2)
	{
		err_cause = keywords.data[2];
		ft_generate_cause(&message, err_cause);
	}

	return (message);
}
