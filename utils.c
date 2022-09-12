/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:56:45 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/12 20:44:40 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

float	ft_mod(float a)
{
	if (a < 0)
		return (a = -a);
	return (a);
}

float	ft_max(float a, float b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	clear_screen_sh(void)
{
	ft_printf("\033[2J");
	ft_printf("\033[0;0f");
}
