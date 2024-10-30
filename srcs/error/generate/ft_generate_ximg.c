/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_ximg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 00:40:04 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/28 02:55:29 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define XIMG_DATA		"data"
#define XIMG_PARAM		"param"
#define XIMG_CREATE		"create"
#define XIMG_FILEPATH	"filepath"

void ft_generate_ximg(char **message, char *err_cause)
{
	char *join;

	ft_generate_type(message, ERR_XIMG);

	if (ft_error_is(err_cause, XIMG_CREATE))
		return (ft_generate_errno(message), (void)0);

	if (ft_error_is(err_cause, XIMG_FILEPATH))
		join = ft_strjoin(*message, ": Invalid XPM path.\n");

	if (ft_error_is(err_cause, XIMG_DATA))
		join = ft_strjoin(*message, ": Faulty image buffer.\n");

	if (ft_error_is(err_cause, XIMG_PARAM))
		join = ft_strjoin(*message, ": Invalid parameters.\n");

	free(*message);
	*message = join;
}
