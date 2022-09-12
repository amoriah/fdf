/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:40:16 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 16:41:21 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	get_zoom(t_fdf **data, t_position *pos, float *x1, float *y1)
{
	(*data)->zoom = 15 + (double)-(*data)->zoom_flag / 10;
	if ((*data)->zoom < 0)
	{
		(*data)->zoom = 0;
		(*data)->figure_height = 0;
	}
	pos->x *= (*data)->zoom;
	pos->y *= (*data)->zoom;
	*x1 *= (*data)->zoom;
	*y1 *= (*data)->zoom;
	pos->z *= (*data)->zoom + (double)-(*data)->figure_height / 10;
	pos->z1 *= (*data)->zoom + (double)-(*data)->figure_height / 10;
}

void	get_position(t_position *pos, float *x1, float *y1, int pos_x)
{
	int	pos_y;

	pos_y = 400;
	pos->x += pos_x;
	*x1 += pos_x;
	pos->y += pos_y;
	*y1 += pos_y;
}

int	choose_position(t_fdf **data)
{
	if ((*data)->width <= 21 && (*data)->height <= 21)
		return (1);
	if ((*data)->width >= 21 && (*data)->width <= 51)
		return (2);
	if ((*data)->height >= 500)
		return (3);
	else
		return (4);
	return (0);
}

void	look_for_position(t_fdf **data, t_position *pos, float *x1, float *y1)
{
	if (choose_position(data) == 1)
		get_position(pos, x1, y1, 450);
	if (choose_position(data) == 2)
		get_position(pos, x1, y1, 550);
	if (choose_position(data) == 3)
		get_position(pos, x1, y1, 700);
	if (choose_position(data) == 4)
		get_position(pos, x1, y1, 550);
}
