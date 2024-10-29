/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_draw_final.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:37:00 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/29 20:42:04 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_error ft_error_draw_final(t_error err, char *text_path)
{
	if (!ft_strncmp(text_path, GOVER_IMG_PATH, ft_strlen(text_path)))
		return (ft_error(err, ERR_RENDGOVER));

	if (!ft_strncmp(text_path, GWON_IMG_PATH, ft_strlen(text_path)))
		return (ft_error(err, ERR_RENDGWON));

	return (OK);
}