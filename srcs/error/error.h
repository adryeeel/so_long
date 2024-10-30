/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:00:03 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/30 02:12:00 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
#define ERROR_H

#include <errno.h>
#include <stdio.h>
#include <stdbool.h>

typedef char *t_error;

#define OK NULL
#define ERR_UNKNOWN				"Failed to generate the error details" // ✅

/* Bad arguments number */
#define ERR_ARGS				"Invalid number of arguments." // ✅

/* X Server Errors */
#define ERR_XSRV				"xsrv"
#define ERR_XSRV_WIN			"xsrv_:-Failed-to-create-window"
#define ERR_XSRV_INIT			"xsrv_:-Failed-to-connect-to-the-X-server"

/* X Image Errors */
#define ERR_XIMG				"ximg"
#define ERR_XIMG_DATA			"ximg_data"
#define ERR_XIMG_PARAM			"ximg_param"
#define ERR_XIMG_CREATE			"ximg_create"
#define ERR_XIMG_FILEPATH		"ximg_filepath"

/* Map Error */
#define ERR_MAP					"map"

/* Map Setup Errors */
#define ERR_MAP_READ			"map_setup_read"
#define ERR_MAP_ALLOC			"map_setup_alloc"
#define ERR_MAP_ISEMPTY			"map_setup_:-Is-empty"
#define ERR_MAP_ISDIR			"map_setup_:-Is-directory"
#define ERR_MAP_EXT				"map_setup_:-Bad-file-extension"

/* Map Path Errors */
#define ERR_MAP_PATH			"map_path"
#define ERR_MAP_PATH_ALLOC		"map_path_:-Failed-to-allocate-memory"
#define ERR_MAP_PATH_EXIT		"map_path_:-Exit-point-is-not-reachable"
#define ERR_MAP_PATH_COLL		"map_path_:-Collectible-is-not-reachable"

/* Map Format Errors */
#define ERR_MAP_COLLECTIBLE		"map_format_:-No-collectibles"
#define ERR_MAP_EXIT			"map_format_:-Bad-exit-points"
#define ERR_MAP_START			"map_format_:-Bad-start-points"
#define ERR_MAP_RECT			"map_format_:-Is-not-rectangular"
#define ERR_MAP_UNKNOWN			"map_format_:-Unknown-components"
#define ERR_MAP_REG				"map_format_:-Rows-are-not-uniform"
#define ERR_MAP_SURROUNDED		"map_format_:-Is-not-surrounded-by-walls"

/* Render Error */
#define ERR_REND				"rend"

/* Scene Render Errors */
#define ERR_RENDSCENE			"rend_game's-scene"
#define ERR_RENDSCENE_DATA		"rend_game's-scene_data"
#define ERR_RENDSCENE_PARAM		"rend_game's-scene_param"
#define ERR_RENDSCENE_CREATE	"rend_game's-scene_create"

/* Background Render Errors */
#define ERR_RENDSPACE			"rend_game's-background"
#define ERR_RENDSPACE_DATA		"rend_game's-background_data"
#define ERR_RENDSPACE_PARAM		"rend_game's-background_param"
#define ERR_RENDSPACE_CREATE	"rend_game's-background_create"
#define ERR_RENDSPACE_FILEPATH	"rend_game's-background_filepath"

/* Wall Render Errors */
#define ERR_RENDWALL			"rend_game's-wall"
#define ERR_RENDWALL_DATA		"rend_game's-wall_data"
#define ERR_RENDWALL_PARAM		"rend_game's-wall_param"
#define ERR_RENDWALL_CREATE		"rend_game's-wall_create"
#define ERR_RENDWALL_FILEPATH	"rend_game's-wall_filepath"

/* Collectible Render Errors */
#define ERR_RENDCOLL			"rend_game's-collectible"
#define ERR_RENDCOLL_DATA		"rend_game's-collectible_data"
#define ERR_RENDCOLL_PARAM		"rend_game's-collectible_param"
#define ERR_RENDCOLL_CREATE		"rend_game's-collectible_create"
#define ERR_RENDCOLL_FILEPATH	"rend_game's-collectible_filepath"

/* Avatar Render Errors */
#define ERR_RENDAVATAR			"rend_game's-avatar"
#define ERR_RENDAVATAR_DATA		"rend_game's-avatar_data"
#define ERR_RENDAVATAR_PARAM	"rend_game's-avatar_param"
#define ERR_RENDAVATAR_CREATE	"rend_game's-avatar_create"
#define ERR_RENDAVATAR_FILEPATH	"rend_game's-avatar_filepath"

/* Avatar Death Render Errors */
#define ERR_RENDEATH			"rend_game's-death"
#define ERR_RENDEATH_DATA		"rend_game's-death_data"
#define ERR_RENDEATH_PARAM		"rend_game's-death_param"
#define ERR_RENDEATH_CREATE		"rend_game's-death_create"
#define ERR_RENDEATH_FILEPATH	"rend_game's-death_filepath"

/* Exit Point Render Errors */
#define ERR_RENDEXIT			"rend_game's-exit"
#define ERR_RENDEXIT_DATA		"rend_game's-exit_data"
#define ERR_RENDEXIT_PARAM		"rend_game's-exit_param"
#define ERR_RENDEXIT_CREATE		"rend_game's-exit_create"
#define ERR_RENDEXIT_FILEPATH	"rend_game's-exit_filepath"

/* Enemy Patrol Render Errors */
#define ERR_RENDPATROL			"rend_game's-patrol"
#define ERR_RENDPATROL_DATA		"rend_game's-patrol_data"
#define ERR_RENDPATROL_PARAM	"rend_game's-patrol_param"
#define ERR_RENDPATROL_CREATE	"rend_game's-patrol_create"
#define ERR_RENDPATROL_FILEPATH	"rend_game's-patrol_filepath"

/* Counter Number Render Errors */
#define ERR_RENDCOUNT			"rend_game's-counter"
#define ERR_RENDCOUNT_DATA		"rend_game's-counter_data"
#define ERR_RENDCOUNT_PARAM		"rend_game's-counter_param"
#define ERR_RENDCOUNT_CREATE	"rend_game's-counter_create"
#define ERR_RENDCOUNT_FILEPATH	"rend_game's-counter_filepath"

/* Game Over Render Errors */
#define ERR_RENDGOVER			"rend_game-over-screen"
#define ERR_RENDGOVER_DATA 		"rend_game-over-screen_data"
#define ERR_RENDGOVER_PARAM 	"rend_game-over-screen_param"
#define ERR_RENDGOVER_CREATE 	"rend_game-over-screen_create"
#define ERR_RENDGOVER_FILEPATH 	"rend_game-over-screen_filepath"

/* Game Won Render Errors */
#define ERR_RENDGWON			"rend_game-won-screen"
#define ERR_RENDGWON_DATA 		"rend_game-won-screen_data"
#define ERR_RENDGWON_PARAM 		"rend_game-won-screen_param"
#define ERR_RENDGWON_CREATE 	"rend_game-won-screen_create"
#define ERR_RENDGWON_FILEPATH 	"rend_game-won-screen_filepath"

bool ft_error_is_map(char *err_cause);
bool ft_error_is_ximg(char *err_cause);
bool ft_error_is(t_error err_a, t_error err_b);

void ft_error_free(t_error err);
void ft_error_print(t_error err);
char *ft_error_message(t_error err);
t_error ft_error(t_error err_a, t_error err_b);

void ft_generate_errno(char **message);
char *ft_error_generate(t_strarr keywords);
void ft_generate_multi(char **message, char *phrase);
void ft_generate_type(char **message, char *err_type);
void ft_generate_map(char **message, char *err_cause);
void ft_generate_what(char **message, char *err_what);
void ft_generate_ximg(char **message, char *err_cause);
void ft_generate_cause(char **message, char *err_reason);

#endif
