/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:41:05 by arocha-b          #+#    #+#             */
/*   Updated: 2024/05/08 01:27:30 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*o_dest;
	const unsigned char	*o_src;

	if (!dest && !src)
		return (NULL);
	o_src = (unsigned char *)src;
	o_dest = dest;
	while (n-- > 0)
		*o_dest++ = *o_src++;
	return (dest);
}
