/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:59:15 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 03:50:51 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	handle_no_event(t_fdf *fdf)
{
	(void) fdf;
	return (0);
}

void	setup_hooks(t_fdf *fdf)
{
	mlx_loop_hook(fdf->wndw.mlx, handle_no_event, fdf);
	mlx_hook(fdf->wndw.win, KeyPress, KeyPressMask, key_press, fdf);
	mlx_hook(fdf->wndw.win, KeyRelease, KeyReleaseMask, key_release, fdf);
	mlx_hook(fdf->wndw.win, ButtonPress, ButtonPressMask, mouse_press, fdf);
	mlx_hook(fdf->wndw.win, ButtonRelease, ButtonReleaseMask, mouse_rele, fdf);
	mlx_hook(fdf->wndw.win, MotionNotify, PointerMotionMask, mouse_move, fdf);
	mlx_hook(fdf->wndw.win, DestroyNotify, NoEventMask, exit_program, fdf);
	write (1, "I feel good :)\n", 16);
}
