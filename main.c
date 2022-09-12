/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:34:33 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/12 20:53:48 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
		return ;
	dst = data->pix_arr + (y * data->line_lenght + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac == 2)
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		check_struct(data);
		read_file(av[1], data);
		data->mlx_ptr = mlx_init();
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
		data->image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->pix_arr = mlx_get_data_addr(data->image, &data->bits_per_pixel,
				&data->line_lenght, &data->endian);
		draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image, 0, 0);
		hooks(data);
		mlx_loop(data->mlx_ptr);
	}
}
