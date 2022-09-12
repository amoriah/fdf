/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:33:55 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 13:30:18 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_step_and_pixel_put(t_fdf *data, t_position pos,
									float x1, float y1)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = x1 - pos.x;
	y_step = y1 - pos.y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(pos.x - x1) || (int)(pos.y - y1))
	{
		my_mlx_pixel_put(data, pos.x, pos.y, data->color);
		pos.x += x_step;
		pos.y += y_step;
	}
}

void	bresenham(t_position pos, float x1, float y1, t_fdf *data)
{
	pos.z = data->z_matrix[(int)pos.y][(int)pos.x];
	pos.z1 = data->z_matrix[(int)y1][(int)x1];
	get_zoom(&data, &pos, &x1, &y1);
	data->color = get_color(data, pos);
	projection(data, &pos.x, &pos.y, &pos.z);
	projection(data, &x1, &y1, &pos.z1);
	look_for_position(&data, &pos, &x1, &y1);
	pos.x += data->shift_x;
	pos.y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	count_step_and_pixel_put(data, pos, x1, y1);
}

void	draw(t_fdf *data)
{
	t_position	pos;

	pos.y = -1;
	while (++pos.y < data->height)
	{
		pos.x = -1;
		while (++pos.x < data->width)
		{
			if (pos.x < data->width - 1)
				bresenham(pos, pos.x + 1, pos.y, data);
			if (pos.y < data->height - 1)
				bresenham(pos, pos.x, pos.y + 1, data);
		}
	}
}
