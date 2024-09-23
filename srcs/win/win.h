/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:02:09 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/23 14:11:18 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_H
#define WIN_H

#include <stdbool.h>
#include "../game/game.h"

typedef struct s_xenv
{
	void *window;
	void *display;
} t_xenv;

typedef struct s_ximg
{
	int bpp;
	int endian;
	int size_line;
	int width;
	int height;

	void *id;
	char *buff;
	char *path;
} t_ximg;

typedef struct s_param
{
	t_xenv *x;
	t_game *g;
} t_param;

/* Window Management */

bool ft_win_setup(t_xenv x, t_game g);
int mlx_close_hook(void *win_ptr, int (*funct)(), void *param);

/* Window Management — Hooks */

int ft_hook_close(void *param);
int ft_hook_key(int key, void *param);

/* Window Management — Rendering */

bool ft_render_bg(void *display, t_ximg *scene);
bool ft_render_scene(t_xenv x, t_game g, t_ximg *scene);

/* Window Management — Xenv */

void ft_xenv_free(t_xenv x);
bool ft_xenv_setup(t_xenv *x);

/* Window Management — Ximg */

void ft_ximg_free(void *display, t_ximg ximg);
bool ft_ximgf_setup(void *display, t_ximg *ximg, char *path);
bool ft_ximg_setup(void *display, t_ximg *ximg, int width, int height);

#endif
