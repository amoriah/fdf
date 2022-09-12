/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:34:43 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 12:58:45 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	if (access(file_name, F_OK) == -1)
		ft_error(ERR);
	fd = open(file_name, O_RDONLY, 0);
	check_fd(fd);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	width = word_count(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_metrix(t_fdf *data, int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		i++;
	}
	delete_leaks(nums, i);
}

void	malloc_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * (data->width));
		check_alloc(&data->z_matrix[i]);
		i++;
	}
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height));
	check_alloc(data->z_matrix);
	malloc_matrix(data);
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_metrix(data, data->z_matrix[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
