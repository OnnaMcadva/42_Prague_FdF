/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:17:47 by annavm            #+#    #+#             */
/*   Updated: 2024/12/25 18:23:23 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	goodbye(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	alloc_null(char *s, char *t)
{
	if (s == NULL)
	{
		free(t);
		goodbye(MEM_ALL);
	}
}

void	free_mapy(char **mapy)
{
	int	i;

	if (!mapy)
		return ;
	i = 0;
	while (mapy[i])
	{
		free(mapy[i]);
		i++;
	}
	free(mapy);
}

int	exit_program(void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	mlx_destroy_image(fdf->wndw.mlx, fdf->img.imgptr);
	mlx_destroy_window(fdf->wndw.mlx, fdf->wndw.win);
	fdf->wndw.win = NULL;
	mlx_destroy_display(fdf->wndw.mlx);
	free(fdf->wndw.mlx);
	fdf->wndw.mlx = NULL;
	free(fdf->map.points);
	fdf->map.points = NULL;
	if (fdf->map.memory)
	{
		free(fdf->map.memory);
		fdf->map.memory = NULL;
	}
	exit(EXIT_SUCCESS);
}

/* valgrind --leak-check=full --show-leak-kinds=all -s ./fdf maps/42.fdf */
