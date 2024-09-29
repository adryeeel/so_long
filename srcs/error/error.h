/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:00:03 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/29 02:13:15 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include <errno.h>
#include <stdio.h>

typedef enum e_error
{
	OK,
	ERR_BAD_ARGS,
	ERR_XSRV_INIT,
	ERR_WIN_CREATE,

	/* Map Setup Errors */
	ERR_MAP_EXT,
	ERR_MAP_READ,
	ERR_MAP_ALLOC,
	ERR_MAP_EMPTY,
	ERR_MAP_ISDIR,

	/* Map Format Errors */
	ERR_MAP_REG,
	ERR_MAP_EXIT,
	ERR_MAP_RECT,
	ERR_MAP_START,
	ERR_MAP_UNKNOWN,
	ERR_MAP_SURRONDED,
	ERR_MAP_COLLECTIBLE,

	/* Map Path Errors */
	ERR_MAP_PATH,
	ERR_MAP_PATH_EXIT,
	ERR_MAP_PATH_COLL,
	ERR_MAP_PATH_ALLOC,

	/* X Images Errors */
	ERR_XIMG_DATA,
	ERR_XIMG_PARAM,
	ERR_XIMG_CREATE,
	ERR_XIMG_FILEPATH,

	/* Scene Render Errors */
	ERR_RENDSCENE_DATA,
	ERR_RENDSCENE_PARAM,
	ERR_RENDSCENE_CREATE,

	/* Background Render Errors */
	ERR_RENDBG_DATA,
	ERR_RENDBG_PARAM,
	ERR_RENDBG_CREATE,
	ERR_RENDBG_FILEPATH,

	/* Wall Render Errors */
	ERR_RENDWALL_DATA,
	ERR_RENDWALL_PARAM,
	ERR_RENDWALL_CREATE,
	ERR_RENDWALL_FILEPATH,
} t_error;

void ft_error_print(t_error err);
t_error ft_error_wall(t_error err);
t_error ft_error_space(t_error err);
t_error ft_error_scene(t_error err);

void ft_puterr_map(t_error err);
void ft_puterr_wall(t_error err);
void ft_puterr_ximg(t_error err);
void ft_puterr_space(t_error err);
void ft_puterr_scene(t_error err);

#endif
