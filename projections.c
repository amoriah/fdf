/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:36:55 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 16:38:35 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	projection(t_fdf *data, float *x, float *y, int *z)
{
	if (data->proj_flag)
		parallel(x, y, z);
	else
		isometric(x, y, *z);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	parallel(float *x, float *y, int *z)
{
	*y = *y * cos(0.8) + *z * sin(0.8);
	*z = -*y * sin(0.8) + *z * cos(0.8);
}
