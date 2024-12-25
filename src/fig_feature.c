/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fig_feature.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:28:10 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 17:45:20 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*void	draw_random_words(t_fdf *fdf)
{
	int		i;
	int		x;
	int		y;
	char	*words[5];
	char	*word;

	words[0] = "P E A C E";
	words[1] = "L O V E";
	words[2] = "U N I T Y";
	words[3] = "R E S P E C T";
	words[4] = "R A V E";
	i = 0;
	while (i < 15)
	{
		x = rand() % WINX;
		y = rand() % WINY;
		word = words[rand() % 5];
		mlx_string_put(fdf->wndw.mlx, fdf->wndw.win, x, y, DJ_CLR, word);
		i++;
	}
}*/

void	draw_stars(t_fdf *fdf)
{
	int		i;
	t_vrtx	star;

	i = 0;
	while (i < 150)
	{
		star.axis[X] = rand() % WINX;
		star.axis[Y] = rand() % WINY;
		star.clr = WHITE;
		draw_one_dot(fdf, star, 2);
		i++;
	}
}

void	bending(t_vrtx *points, int len, float range)
{
	int		i;
	float	bend_value;

	i = 0;
	while (i < len)
	{
		bend_value = ((points[i].axis[X] * points[i].axis[X]) * (range)) + \
			(points[i].axis[Y] * points[i].axis[Y]) * (range);
		points[i].axis[Z] = points[i].axis[Z] - bend_value;
		i++;
	}
}

void	scale(t_vrtx *points, int scale, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X] = points[i].axis[X] * scale;
		points[i].axis[Y] = points[i].axis[Y] * scale;
		points[i].axis[Z] = points[i].axis[Z] * scale;
		i++;
	}
}

void	traslate(t_vrtx *points, t_vrtx move, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X] = points[i].axis[X] + move.axis[X];
		points[i].axis[Y] = points[i].axis[Y] + move.axis[Y];
		points[i].axis[Z] = points[i].axis[Z] + move.axis[Z];
		i++;
	}
}
