/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:38:20 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 20:05:38 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <time.h>
# include <stdint.h>
# include <stddef.h>

# include <mlx.h>
# include <libft.h>

# include "fdf_define.h"
# include "keyboard.h"
# include "fdf_struct.h"

/* fdf */
int		map_name(const char *s);
int		main(int argc, char *argv[]);

/* fig_feature */
void	draw_stars(t_fdf *fdf);
void	bending(t_vrtx *points, int len, float range);
void	scale(t_vrtx *points, int scale, int len);
void	traslate(t_vrtx *points, t_vrtx move, int len);

/* free_exit */
void	goodbye(char *s);
void	alloc_null(char*s, char *t);
void	free_mapy(char **mapy);
int		exit_program(void *f);

/* graphics_prim.c */
int		draw_line(t_fdf *fdf, t_vrtx start, t_vrtx end);
void	contorno_line(t_vrtx *point, t_fdf *fdf, int density, int line);
void	draw_contorno_frame(t_fdf *fdf, t_vrtx *contorno);
void	draw_one_dot(t_fdf *fdf, t_vrtx point, int radius);

/* key_board */
void	key_adjust_map(int key, t_fdf *fdf);
void	key_rotate_map(int key, t_fdf *fdf);
void	key_reset_map(int key, t_fdf *fdf);
int		key_press(int key, void *param);
int		key_release(int key, void *param);

/* key_mouse */
int		mouse_move(int x, int y, void *param);
int		mouse_rele(int button, int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);

/* loading_bar */
void	print_dj(t_fdf *fdf, int x, int y, char *str);
void	draw_hotkeys_dj(t_fdf *fdf);
void	print_str(t_fdf *fdf, int x, int y, char *str);
void	loading_bar(t_fdf *fdf);

/* map_color */
t_rgb	get_rgb(int color);
int		merge_rgb(t_rgb rgb);
int		gradient(int startclr, int endclr, int len, int pix);
void	load_color(int max, int min, t_vrtx *point, t_clrs	clrs);
void	map_color(t_map *map);

/* map_drawing */
void	draw_dots(t_fdf *fdf, t_vrtx *project);
void	drawing(t_fdf *fdf, t_vrtx *projec, int fit);

/* map_handle */
void	base_color(t_map *map);
void	map_reset(t_map *map, int total);
void	map_handle(t_map *map, char *path);

/* map_points */
void	map_points(t_map *map);

/* map_read */
char	*map_read(int fd);

/* map_render */
void	generate_background(t_fdf *fdf, int backclr, int menuclr);
void	isometric_projection(t_vrtx *src, t_vrtx *dest, int len);
void	parse_map(t_fdf *fdf, t_vrtx *des);
void	copy_map(t_vrtx *src, t_vrtx *dst, int len);
int		map_render(t_fdf *fdf, int fit);

/* map_size */
void	map_size(t_map *map);

/* math_angle */
void	an_angle(float *ang, float value);
void	math_angle(int key, t_fdf *fdf);

/* math_geom */
void	z_division(t_vrtx *vertices, float z_scale, int count);
void	relievo(t_map *map);
void	parallel(t_map *map);

/* math_move */
void	matrix_init(float (*matrix)[3]);
t_vrtx	mul_mat(float matrix[3][3], t_vrtx point);
void	rotate_x(t_vrtx *vrtx, t_vrtx *des, float ang, int len);
void	rotate_y(t_vrtx *vrtx, t_vrtx *des, float ang, int len);
void	rotate_z(t_vrtx *vrtx, t_vrtx *des, float ang, int len);

/* put_pixel */
int		valid_pixel(t_vrtx pixel);
int		get_color(t_fdf *fdf, int color);
void	set_color(char *buffer, int endian, int color, int alpha);
int		put_pixel(t_fdf *fdf, t_vrtx pixel);

/* setup_hooks */
void	setup_hooks(t_fdf *fdf);

/* switch_color */
void	colorize(t_map *map);
void	switch_color(int key, t_map *map);

/* win_handle */
void	win_handle(t_fdf *fdf);

#endif