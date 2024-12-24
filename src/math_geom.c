/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_geom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:06:10 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 17:18:20 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	z_division(t_vrtx *vertices, float z_scale, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		vertices[i].axis[Z] = vertices[i].axis[Z] / z_scale;
		i++;
	}
}

void	relievo(t_map *map)
{
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 30;
	map->bend = 0;
	map->src.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->src.axis[Y] = WINY / 2;
}

void	parallel(t_map *map)
{
	int	i;

	map->ang[X] = 270;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	map->bend = 0;
	map->src.axis[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->src.axis[Y] = WINY / 2;
	i = 0;
	while (i < map->len)
	{
		map->points[i].axis[Z] = -map->points[i].axis[Z];
		i++;
	}
}
