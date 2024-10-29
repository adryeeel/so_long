/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:18:12 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/28 01:03:35 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error(t_error err_a, t_error err_b)
{
	t_error join;
	t_error new_err;
	t_error err_last;

	if (!err_a || !err_b)
		return (NULL);

	err_last = ft_strrchr(err_a, '_') + 1;
	join = ft_strjoin(err_b, "_");
	new_err = ft_strjoin(join, err_last);

	free(join);
	return (new_err);
}