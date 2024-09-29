/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:02:09 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/29 02:21:57 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_H
#define WIN_H

typedef enum e_error t_error;
typedef struct s_game t_game;

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

t_error ft_win_setup(t_xenv x, t_game g);
int mlx_close_hook(void *win_ptr, int (*funct)(), void *param);

/* Window Management — Hooks */

int ft_hook_close(void *param);
int ft_hook_key(int key, void *param);

/* Window Management — Rendering */

t_error ft_render_scene(t_xenv x, t_game g, t_ximg *scene);
void ft_render_tile(t_ximg *dst, t_ximg tile, t_coord dst_p);
t_error ft_render_wall(void *display, t_map map, t_ximg *scene);
t_error ft_render_space(void *display, t_map map, t_ximg *scene);

/* Window Management — Xenv */

void ft_xenv_free(t_xenv x);
t_error ft_xenv_setup(t_xenv *x);

/* Window Management — Ximg */

void ft_ximg_free(void *display, t_ximg ximg);
t_error ft_ximgf_setup(void *display, t_ximg *ximg, char *path);
t_error ft_ximg_setup(void *display, t_ximg *ximg, int width, int height);

#endif
