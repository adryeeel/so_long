/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:00:03 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/24 14:38:21 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include <errno.h>
#include <stdio.h>
typedef enum e_error
{
	OK,
	ERR_XSRV_INIT,
	ERR_WIN_CREATE,
	ERR_BAD_ARGS,
	ERR_MAP_READ,
	ERR_MAP_ALLOC,
	ERR_MAP_EMPTY,
	ERR_MAP_RECT,
	ERR_MAP_SYMM,
	ERR_MAP_MATRIX,
	ERR_XIMG_DATA,
	ERR_XIMG_PARAM,
	ERR_XIMG_CREATE,
	ERR_XIMG_FILEPATH,
	ERR_RENDSCENE_DATA,
	ERR_RENDSCENE_CREATE,
	ERR_RENDBG_CREATE,
	ERR_RENDBG_DATA,
	ERR_RENDBG_FILEPATH,
} t_error;

void ft_print_map(t_error err);
void ft_print_ximg(t_error err);
void ft_print_rendbg(t_error err);
void ft_print_rendscene(t_error err);

void ft_error_print(t_error err);
t_error ft_transl_rendbg(t_error err);
t_error ft_transl_rendscene(t_error err);

#endif
