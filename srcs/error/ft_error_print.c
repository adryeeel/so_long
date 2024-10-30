/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:11:08 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/30 02:11:52 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_error_print(t_error err)
{
	char *message;

	ft_putendl_fd("Error", STDERR_FILENO);

	if (ft_error_is(err, ERR_ARGS))
		return (ft_putendl_fd(ERR_ARGS, STDERR_FILENO), (void)0);

	message = ft_error_message(err);
	if (!message)
		return (perror(ERR_UNKNOWN), (void)0);

	ft_putstr_fd(message, STDERR_FILENO);
	free(message);
	ft_error_free(err);
}