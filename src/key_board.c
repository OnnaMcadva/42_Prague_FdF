/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:39:46 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 19:08:17 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	key_adjust_map(int key, t_fdf *fdf)
{
	if (key == B)
	{
		if (fdf->keys.b_keyctrl)
			fdf->map.bend -= 0.001;
		else
			fdf->map.bend += 0.001;
	}
	if (key == NP_PLUS)
	{
		if (fdf->keys.b_keyctrl)
			fdf->map.scale = fdf->map.scale * 1.5;
		if (fdf->map.zdivisor > 1)
			fdf->map.zdivisor -= 10;
	}
	if (key == NP_MINUS)
	{
		if (fdf->keys.b_keyctrl)
			fdf->map.scale = fdf->map.scale / 1.5;
		fdf->map.zdivisor += 10;
	}
	if (key == I)
	{
		relievo(&fdf->map);
		map_render(fdf, FIT);
	}
}

void	key_rotate_map(int key, t_fdf *fdf)
{
	if (key == Q)
		fdf->map.ang[X] += 15;
	if (key == E)
		fdf->map.ang[X] -= 15;
	if (key == A)
		fdf->map.ang[Y] += 15;
	if (key == D)
		fdf->map.ang[Y] -= 15;
	if (key == W)
		fdf->map.ang[Z] += 15;
	if (key == S)
		fdf->map.ang[Z] -= 15;
	if (key == K)
		fdf->map.b_words = !fdf->map.b_words;
	if (key == L)
		fdf->map.b_stars = !fdf->map.b_stars;
	map_render(fdf, FIT);
	if (key == F)
		map_render(fdf, FIT);
	if (key == CTRL)
		fdf->keys.b_keyctrl = 1;
}

void	key_reset_map(int key, t_fdf *fdf)
{
	if (key == ESC)
		exit_program(fdf);
	if (key == R)
	{
		map_reset(&fdf->map, 0);
		fdf->map.proportion = \
		fdf->map.lims.axis[Z] / fdf->map.lims.axis[X];
		if (fdf->map.proportion > 0.5)
			fdf->map.zdivisor = fdf->map.proportion * 20;
		colorize(&fdf->map);
		map_render(fdf, FIT);
	}
	if (key == P)
	{
		parallel(&fdf->map);
		map_render(fdf, FIT);
	}
}

int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	math_angle(key, fdf);
	key_reset_map(key, fdf);
	key_rotate_map(key, fdf);
	key_adjust_map(key, fdf);
	if (key == NP_2 || key == NP_3 || key == NP_4)
		switch_color(key, &fdf->map);
	map_render(fdf, FREE);
	return (0);
}

int	key_release(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == CTRL)
		fdf->keys.b_keyctrl = 0;
	return (0);
}
