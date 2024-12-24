/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:58:30 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 17:11:11 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_mlx(t_fdf *fdf)
{
	fdf->wndw.mlx = mlx_init();
	if (!fdf->wndw.mlx)
	{
		ft_putendl_fd("Error: mlx_init failed!", 2);
		exit(1);
	}
}

static void	create_window(t_fdf *fdf)
{
	fdf->wndw.win = mlx_new_window(fdf->wndw.mlx, WINX, \
		WINY, "~   FdF - AnMaka   ~");
	if (!fdf->wndw.win)
	{
		ft_putendl_fd("Error: mlx_new_window failed!", 2);
		mlx_destroy_display(fdf->wndw.mlx);
		free(fdf->wndw.mlx);
		exit(1);
	}
}

static void	create_image(t_fdf *fdf)
{
	fdf->img.imgptr = mlx_new_image(fdf->wndw.mlx, WINX, WINY);
	if (!fdf->img.imgptr)
	{
		ft_putendl_fd("Error: mlx_new_image failed!", 2);
		mlx_destroy_window(fdf->wndw.mlx, fdf->wndw.win);
		mlx_destroy_display(fdf->wndw.mlx);
		free(fdf->wndw.mlx);
		exit(1);
	}
	fdf->img.data = mlx_get_data_addr(fdf->img.imgptr, \
		&fdf->img.bpp, &fdf->img.line, &fdf->img.endian);
	if (!fdf->img.data)
	{
		ft_putendl_fd("Error: mlx_get_data_addr failed!", 2);
		mlx_destroy_image(fdf->wndw.mlx, fdf->img.imgptr);
		mlx_destroy_window(fdf->wndw.mlx, fdf->wndw.win);
		mlx_destroy_display(fdf->wndw.mlx);
		free(fdf->wndw.mlx);
		exit(1);
	}
}

void	win_handle(t_fdf *fdf)
{
	fdf->map.renders = 0;
	fdf->map.proportion = fdf->map.lims.axis[Z] / fdf->map.lims.axis[X];
	if (fdf->map.proportion > 0.5)
		fdf->map.zdivisor = fdf->map.proportion * 20;
	fdf->keys.b_keyctrl = 0;
	fdf->keys.b_mouse_l = 0;
	fdf->keys.b_mouse_r = 0;
	init_mlx(fdf);
	create_window(fdf);
	create_image(fdf);
}
