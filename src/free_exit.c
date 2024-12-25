/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:17:47 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 19:46:46 by annavm           ###   ########.fr       */
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
	mlx_destroy_window(fdf->wndw.mlx, fdf->wndw.win);
		fdf->wndw.win = NULL;
	free(fdf->map.points);
	exit(EXIT_SUCCESS);
}


/* valgrind --leak-check=full --show-leak-kinds=all -s ./fdf maps/42.fdf */

