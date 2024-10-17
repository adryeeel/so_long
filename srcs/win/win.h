/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocha-b <arocha-b@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:02:09 by arocha-b          #+#    #+#             */
/*   Updated: 2024/10/17 17:05:20 by arocha-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIN_H
#define WIN_H

typedef enum e_error t_error;
typedef struct s_game t_game;

typedef struct s_ximg
{
	void *id;
	char *buff;
	char *path;

	int bpp;
	int width;
	int height;
	int endian;
	int size_line;
} t_ximg;

typedef struct s_xenv
{
	t_ximg coll;
	t_ximg scene;
	t_ximg patrol;
	t_ximg number;

	void *window;
	void *display;
} t_xenv;

typedef struct s_param
{
	t_xenv *x;
	t_game *g;
} t_param;

/* Window Management */

t_error ft_win_draw(t_xenv x, t_game g);
t_error ft_win_setup(t_xenv *x, t_game g, t_param *args);
int mlx_close_hook(void *win_ptr, int (*funct)(), void *param);

/* Window Management — Hooks */

int ft_hook_loop(void *param);
int ft_hook_close(void *param);
int ft_hook_key(int key, void *param);

/* Window Management — Drawing */

bool ft_draw_fadeout(t_xenv x);
void ft_draw_gameover(t_xenv x);
t_error ft_draw_move(t_xenv x, t_game g);
t_error ft_draw_anim(t_xenv x, t_game g);
t_error ft_draw_death(t_xenv x, t_game g);
t_error ft_draw_counter(t_xenv x, t_game g);
t_error ft_draw_comp(t_xenv x, t_game g, t_mapc comp);
t_error ft_draw_background(void *display, t_ximg *tex);
void ft_draw_at(t_ximg *dst, t_ximg src, t_coord coord);
t_error ft_draw_frame(t_xenv x, t_map map, t_mapc comp, size_t frame_n);

/* Window Management — X Environment */

void ft_xenv_free(t_xenv x);
t_error ft_xenv_setup(t_xenv *x, t_map map);

/* Window Management — X Images */

void ft_ximg_free(void *display, t_ximg ximg);
void ft_ximg_copy(t_ximg *dst, t_ximg src, t_coord dst_p);
void ft_ximg_fill_alpha(t_ximg *dst, t_ximg src, t_coord dst_p);
t_error ft_ximgf_setup(void *display, t_ximg *ximg, char *path);
t_error ft_ximg_sprite(t_xenv x, bool orient, t_ximg *tex, t_mapc comp);
t_error ft_ximg_setup(void *display, t_ximg *ximg, int width, int height);
t_error ft_ximg_frame(void *display, t_ximg frameset, t_ximg *frame, size_t n);

#endif
