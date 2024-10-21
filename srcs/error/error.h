/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:00:03 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/21 18:42:40 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include <errno.h>
#include <stdio.h>

typedef char *t_error;

#define OK NULL

/* Bad arguments number */
#define ERR_ARGS				"args"

/* Xorg Setup Errors */
#define ERR_XSRV_WIN			"xsrv_win"
#define ERR_XSRV_INIT			"xsrv_init"

/* X Image Errors */
#define ERR_XIMG_DATA			"ximg_data"
#define ERR_XIMG_PARAM			"ximg_param"
#define ERR_XIMG_CREATE			"ximg_create"
#define ERR_XIMG_FILEPATH		"ximg_filepath"

/* Map Setup Errors */
#define ERR_MAP_EXT				"map_setup_ext"
#define ERR_MAP_READ			"map_setup_read"
#define ERR_MAP_ALLOC			"map_setup_alloc"
#define ERR_MAP_EMPTY			"map_setup_empty"
#define ERR_MAP_ISDIR			"map_setup_isdir"

/* Map Path Errors */
#define ERR_MAP_PATH			"map_path"
#define ERR_MAP_PATH_EXIT		"map_path_exit"
#define ERR_MAP_PATH_COLL		"map_path_coll"
#define ERR_MAP_PATH_ALLOC		"map_path_alloc"

/* Map Format Errors */
#define ERR_MAP_REG				"map_format_reg"
#define ERR_MAP_EXIT			"map_format_exit"
#define ERR_MAP_RECT			"map_format_rect"
#define ERR_MAP_START			"map_format_start"
#define ERR_MAP_UNKNOWN			"map_format_unknown"
#define ERR_MAP_SURROUNDED		"map_format_surrounded"
#define ERR_MAP_COLLECTIBLE		"map_format_collectible"

/* Scene Render Errors */
#define ERR_RENDSCENE_DATA		"rend_scene_data"
#define ERR_RENDSCENE_PARAM		"rend_scene_param"
#define ERR_RENDSCENE_CREATE	"rend_scene_create"

/* Background Render Errors */
#define ERR_RENDBG_DATA			"rend_bg_data"
#define ERR_RENDBG_PARAM		"rend_bg_param"
#define ERR_RENDBG_CREATE		"rend_bg_create"
#define ERR_RENDBG_FILEPATH		"rend_bg_filepath"

/* Wall Render Errors */
#define ERR_RENDWALL_DATA		"rend_wall_data"
#define ERR_RENDWALL_PARAM		"rend_wall_param"
#define ERR_RENDWALL_CREATE		"rend_wall_create"
#define ERR_RENDWALL_FILEPATH	"rend_wall_filepath"

/* Collectible Render Errors */
#define ERR_RENDCOLL_DATA		"rend_coll_data"
#define ERR_RENDCOLL_PARAM		"rend_coll_param"
#define ERR_RENDCOLL_CREATE		"rend_coll_create"
#define ERR_RENDCOLL_FILEPATH	"rend_coll_filepath"

/* Avatar Render Errors */
#define ERR_RENDAVATAR_DATA		"rend_avatar_data"
#define ERR_RENDAVATAR_PARAM	"rend_avatar_param"
#define ERR_RENDAVATAR_CREATE	"rend_avatar_create"
#define ERR_RENDAVATAR_FILEPATH	"rend_avatar_filepath"

/* Avatar Death Render Errors */
#define ERR_RENDEATH_DATA		"rend_death_data"
#define ERR_RENDEATH_PARAM		"rend_death_param"
#define ERR_RENDEATH_CREATE		"rend_death_create"
#define ERR_RENDEATH_FILEPATH	"rend_death_filepath"

/* Exit Point Render Errors */
#define ERR_RENDEXIT_DATA		"rend_exit_data"
#define ERR_RENDEXIT_PARAM		"rend_exit_param"
#define ERR_RENDEXIT_CREATE		"rend_exit_create"
#define ERR_RENDEXIT_FILEPATH	"rend_exit_filepath"

/* Enemy Patrol Render Errors */
#define ERR_RENDPATROL_DATA		"rend_patrol_data"
#define ERR_RENDPATROL_PARAM	"rend_patrol_param"
#define ERR_RENDPATROL_CREATE	"rend_patrol_create"
#define ERR_RENDPATROL_FILEPATH	"rend_patrol_filepath"

/* Counter Number Render Errors */
#define ERR_RENDCOUNT_DATA		"rend_count_data"
#define ERR_RENDCOUNT_PARAM		"rend_count_param"
#define ERR_RENDCOUNT_CREATE	"rend_count_create"
#define ERR_RENDCOUNT_FILEPATH	"rend_count_filepath"

/* Game Over Render Errors */
#define ERR_RENDGOVER_DATA 		"rend_gover_data"
#define ERR_RENDGOVER_PARAM 	"rend_gover_param"
#define ERR_RENDGOVER_CREATE 	"rend_gover_create"
#define ERR_RENDGOVER_FILEPATH 	"rend_gover_filepath"

/* Game Won Render Errors */
#define ERR_RENDGWON_DATA 		"rend_gwon_data"
#define ERR_RENDGWON_PARAM 		"rend_gwon_param"
#define ERR_RENDGWON_CREATE 	"rend_gwon_create"
#define ERR_RENDGWON_FILEPATH 	"rend_gwon_lepath"

void ft_error_print(t_error err);
void ft_error_generate(t_error err);

#endif
