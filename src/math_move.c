/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:52:51 by annavm            #+#    #+#             */
/*   Updated: 2024/12/24 01:22:32 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	matrix_init(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_vrtx	mul_mat(float matrix[3][3], t_vrtx point)
{
	int		i;
	int		k;
	t_vrtx	result;

	result = point;
	i = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		result.clr = point.clr;
		k = 0;
		while (k < 3)
		{
			result.axis[i] += matrix[i][k] * point.axis[k];
			k++;
		}
		i++;
	}
	return (result);
}

void	rotate_x(t_vrtx *vrtx, t_vrtx *des, float ang, int len)
{
	int		i;
	float	rad;
	float	des_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix_init(des_matrix);
	des_matrix[0][0] = 1;
	des_matrix[1][1] = cos(rad);
	des_matrix[1][2] = -sin(rad);
	des_matrix[2][1] = sin(rad);
	des_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		des[i] = mul_mat(des_matrix, vrtx[i]);
		i++;
	}
}

void	rotate_y(t_vrtx *vrtx, t_vrtx *des, float ang, int len)
{
	int		i;
	float	rad;
	float	des_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix_init(des_matrix);
	des_matrix[0][0] = cos(rad);
	des_matrix[0][2] = sin(rad);
	des_matrix[1][1] = 1;
	des_matrix[2][0] = -sin(rad);
	des_matrix[2][2] = cos(rad);
	i = 0;
	while (i < len)
	{
		des[i] = mul_mat(des_matrix, vrtx[i]);
		i++;
	}
}

void	rotate_z(t_vrtx *points, t_vrtx *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	project_matrix[3][3];

	rad = ang * M_PI / 180;
	matrix_init(project_matrix);
	project_matrix[0][0] = cos(rad);
	project_matrix[0][1] = -sin(rad);
	project_matrix[1][0] = sin(rad);
	project_matrix[1][1] = cos(rad);
	project_matrix[2][2] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = mul_mat(project_matrix, points[i]);
		i++;
	}
}
