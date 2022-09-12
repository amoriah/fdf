/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:04:58 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 16:31:46 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	make_image_again(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->image);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->pix_arr = mlx_get_data_addr(data->image, &data->bits_per_pixel,
			&data->line_lenght, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image, 0, 0);
}

void	key_move(t_fdf *data, int key)
{
	if (key == ENT)
		ft_printf("Enter\n");
	if (key == I_KEY)
		data->proj_flag = 0;
	if (key == P_KEY)
		data->proj_flag = 1;
	if (key == UP || key == W_KEY)
		data->shift_y -= 10;
	if (key == DOWN || key == S_KEY)
		data->shift_y += 10;
	if (key == LEFT || key == A_KEY)
		data->shift_x -= 10;
	if (key == RIGHT || key == D_KEY)
		data->shift_x += 10;
	if (key == PLUS)
		data->zoom_flag--;
	if (key == MINUS)
		data->zoom_flag++;
	if (key == FIGURE_DOWN)
		data->figure_height++;
	if (key == FIGURE_UP)
		data->figure_height--;
	make_image_again(data);
}

int	esc_key(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->image);
	ft_printf("Exit\n");
	exit(-1);
}

int	deal_key(int key, t_fdf *data)
{
	clear_screen_sh();
	ft_printf("key = %d\n", key);
	if (key == ESC)
		esc_key(data);
	key_move(data, key);
	draw(data);
	return (0);
}

void	hooks(t_fdf *data)
{
	mlx_hook(data->win_ptr, KEYPRESS, 0, deal_key, data);
	mlx_hook(data->win_ptr, 29, 0, esc_key, data);
	mlx_hook(data->win_ptr, 17, 0, esc_key, data);
}
