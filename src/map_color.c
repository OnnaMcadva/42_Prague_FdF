/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 21:23:06 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 14:34:08 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_rgb	get_rgb(int color)
{
	t_rgb	rgb;

	rgb.red = (color >> 16) & 0xFF;
	rgb.green = (color >> 8) & 0xFF;
	rgb.blue = color & 0xFF;
	return (rgb);
}

int	merge_rgb(t_rgb rgb)
{
	return ((rgb.red << 16) + (rgb.green << 8) + rgb.blue);
}

int	gradient(int startclr, int endclr, int len, int pix)
{
	t_rgb	start_rgb;
	t_rgb	end_rgb;
	t_rgb	new_rgb;
	double	incr[3];

	start_rgb = get_rgb(startclr);
	end_rgb = get_rgb(endclr);
	incr[0] = (double)(end_rgb.red - start_rgb.red) / (double)len;
	incr[1] = (double)(end_rgb.green - start_rgb.green) / (double)len;
	incr[2] = (double)(end_rgb.blue - start_rgb.blue) / (double)len;
	new_rgb.red = start_rgb.red + ft_round(pix * incr[0]);
	new_rgb.green = start_rgb.green + ft_round(pix * incr[1]);
	new_rgb.blue = start_rgb.blue + ft_round(pix * incr[2]);
	return (merge_rgb(new_rgb));
}

void	load_color(int max, int min, t_vrtx *point, t_clrs	clrs)
{
	point->paint = 1;
	point->clr = DEFA_CLR;
	if (point->hex_clr > 0)
	{
		point->clr = point->hex_clr;
		return ;
	}
	if (point->axis[Z] == max)
		point->clr = clrs.topclr;
	else if (point->axis[Z] == 0)
		point->clr = clrs.groundclr;
	else if (point->axis[Z] == min && min != 0)
		point->clr = clrs.bottomclr;
	else if (point->axis[Z] > 0)
		point->clr = gradient(clrs.groundclr, clrs.topclr, \
		max, point->axis[Z]);
	else
		point->clr = gradient(clrs.bottomclr, clrs.groundclr, \
		-min, - (min - point->axis[Z]));
}

void	map_color(t_map *map)
{
	int	i;

	ft_printf("Total points: %d, Max Z: %d, Min Z: %d\n", map->len, \
		(int)map->lims.axis[Z], map->zmin);
	i = 0;
	while (i < map->len)
	{
		load_color((int)map->lims.axis[Z], map->zmin, \
		&map->points[i], map->clrs);
		i++;
	}
}
