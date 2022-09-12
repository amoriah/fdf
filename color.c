/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:56:02 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 13:26:27 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

unsigned int	blue_pink(int h)
{
	if (h > 100)
		return (YELLOW);
	if (h > 75)
		return (YELLOW1);
	if (h > 50)
		return (YELLOW2);
	if (h > 25)
		return (YELLOW3);
	if (h > 15)
		return (PINK);
	if (h > 10)
		return (PINK1);
	if (h > 5)
		return (PINK2);
	if (h > 0)
		return (BLUE);
	if (h > -10)
		return (BLUE1);
	if (h > -20)
		return (BLUE2);
	if (h > -50)
		return (BLUE3);
	return (GREEN);
}

unsigned int	earth_color(int h)
{
	if (h > 70)
		return (SNOW);
	if (h > 62)
		return (ROCKS);
	if (h > 50)
		return (KHAKI);
	if (h > 10)
		return (KHAKI);
	if (h > 1)
		return (DIRTY_GREEN);
	if (h > 0)
		return (DIRTY_YELLOW);
	if (h > -5)
		return (DARK_BLUE);
	if (h > -10)
		return (DARK_BLUE2);
	if (h > -30)
		return (GRAY_BLUE);
	return (VERY_DARK_BLUE);
}

unsigned int	get_color(t_fdf *data, t_position pos)
{
	unsigned int	c;

	if (data->width >= 100 && data->height >= 100)
		c = earth_color(pos.z1);
	else
		c = blue_pink(pos.z1);
	return (c);
}
