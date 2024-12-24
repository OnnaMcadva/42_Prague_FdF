/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:59:04 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 16:22:09 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	colorize(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		load_color((int)map->lims.axis[Z], map->zmin, \
		&map->points[i], map->clrs);
		i++;
	}
}

void	switch_color(int key, t_map *map)
{
	if (key == NP_2)
	{
		map->clrs.backclr = WHITE;
		map->clrs.bottomclr = CARBON;
		map->clrs.topclr = CARBON;
		map->clrs.groundclr = CARBON;
	}
	if (key == NP_3)
	{
		map->clrs.backclr = CARBON;
		map->clrs.bottomclr = WHITE;
		map->clrs.topclr = WHITE;
		map->clrs.groundclr = WHITE;
	}
	if (key == NP_4)
	{
		map->clrs.backclr = BACK_CLR;
		map->clrs.bottomclr = SUPERBLUE;
		map->clrs.topclr = ORANGE;
		map->clrs.groundclr = INDIGO;
	}
	colorize(map);
}
