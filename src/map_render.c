/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:41:36 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 18:57:36 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	generate_background(t_fdf *fdf, int backclr, int menuclr)
{
	int	axis[2];
	int	pixel;
	int	color;

	backclr = get_color(fdf, backclr);
	menuclr = get_color(fdf, menuclr);
	axis[X] = 0;
	axis[Y] = 0;
	while (axis[Y] < WINY)
	{
		while (axis[X] < WINX)
		{
			if (axis[X] < MENU_WIDTH)
				color = menuclr;
			else
				color = backclr;
			pixel = (axis[Y] * fdf->img.line) + (axis[X] * 4);
			set_color(&fdf->img.data[pixel], \
						fdf->img.endian, color, 1);
			axis[X]++;
		}
		axis[Y]++;
		axis[X] = 0;
	}
}

void	isometric_projection(t_vrtx *src, t_vrtx *dest, int len)
{
	int		i;
	float	iso_x;
	float	iso_y;

	i = 0;
	while (i < len)
	{
		iso_x = (src[i].axis[X] - src[i].axis[Y]) * cos(M_PI / 6);
		iso_y = (src[i].axis[X] + src[i].axis[Y]) * sin(M_PI / 6) \
			- src[i].axis[Z];
		dest[i].axis[X] = iso_x;
		dest[i].axis[Y] = iso_y;
		dest[i].axis[Z] = src[i].axis[Z];
		dest[i].clr = src[i].clr;
		dest[i].paint = src[i].paint;
		i++;
	}
}

void	parse_map(t_fdf *fdf, t_vrtx *des)
{
	z_division(des, fdf->map.zdivisor, fdf->map.len);
	bending(des, fdf->map.len, fdf->map.bend);
	rotate_x(des, des, fdf->map.ang[X], fdf->map.len);
	rotate_y(des, des, fdf->map.ang[Y], fdf->map.len);
	rotate_z(des, des, fdf->map.ang[Z], fdf->map.len);
	isometric_projection(des, des, fdf->map.len);
	scale (des, fdf->map.scale, fdf->map.len);
	traslate(des, fdf->map.src, fdf->map.len);
}

void	copy_map(t_vrtx *src, t_vrtx *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

int	map_render(t_fdf *fdf, int fit)
{
	t_vrtx	*design;

	design = malloc (fdf->map.len * sizeof(t_vrtx));
	if (design == NULL)
		goodbye(MEM_ALL);
	fdf->map.renders = fdf->map.renders + 1;
	generate_background(fdf, fdf->map.clrs.backclr, \
		fdf->map.clrs.menuclr);
	copy_map(fdf->map.points, design, fdf->map.len);
	parse_map(fdf, design);
	drawing(fdf, design, fit);
	mlx_put_image_to_window(fdf->wndw.mlx, fdf->wndw.win, \
		fdf->img.imgptr, 0, 0);
	loading_bar(fdf);
	free (design);
	return (1);
}
