/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:02:09 by arocha-b          #+#    #+#             */
/*   Updated: 2024/09/30 22:23:41 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_H
#define WIN_H

typedef enum e_error t_error;
typedef struct s_game t_game;

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

typedef struct s_xenv
{
	void *window;
	void *display;
	t_ximg coll;
	t_ximg scene;
} t_xenv;

typedef struct s_param
{
	t_xenv *x;
	t_game *g;
} t_param;

/* Window Management */

t_error ft_win_setup(t_xenv *x, t_game g);
int mlx_close_hook(void *win_ptr, int (*funct)(), void *param);

/* Window Management — Hooks */

int ft_hook_loop(void *param);
int ft_hook_close(void *param);
int ft_hook_key(int key, void *param);

/* Window Management — Rendering */

t_error ft_draw_anim(t_xenv x, t_game g);
t_error ft_draw_static(t_xenv x, t_game g);
t_error ft_draw_coll(t_xenv x, t_game g, size_t frame_n);
t_error ft_draw_move(t_xenv x, t_map map, t_coord avatar);
t_error ft_draw_avatar(t_xenv x, t_map map, t_coord avatar);
t_error ft_draw_comp(t_xenv x, t_map map, t_mapc comp, char *tex_path);

/* Window Management — Xenv */

void ft_xenv_free(t_xenv x);
t_error ft_xenv_setup(t_xenv *x, t_map map);

/* Window Management — Ximg */

void ft_ximg_free(void *display, t_ximg ximg);
void ft_ximg_copy(t_ximg *dst, t_ximg src, t_coord dst_p);
t_error ft_ximgf_setup(void *display, t_ximg *ximg, char *path);
t_error ft_ximg_setup(void *display, t_ximg *ximg, int width, int height);
t_error ft_ximg_frame(t_xenv x, t_ximg frameset, t_ximg *frame, size_t frame_n);

#endif
