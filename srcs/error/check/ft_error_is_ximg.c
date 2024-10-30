/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_is_ximg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:14:39 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/29 19:17:08 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#define XIMG_DATA		"data"
#define XIMG_PARAM		"param"
#define XIMG_CREATE		"create"
#define XIMG_FILEPATH	"filepath"

bool ft_error_is_ximg(char *err_cause)
{
	if (ft_error_is(err_cause, XIMG_DATA))
		return (true);

	if (ft_error_is(err_cause, XIMG_CREATE))
		return (true);

	if (ft_error_is(err_cause, XIMG_PARAM))
		return (true);

	if (ft_error_is(err_cause, XIMG_FILEPATH))
		return (true);

	return (false);
}
