/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:47:29 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 12:12:12 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(int **array)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (array[i])
		i++;
	c = i;
	while (j < c)
	{
		free(array[i]);
		i--;
		j++;
	}
	free(array);
}

void	delete_leaks(char **line, int len)
{
	int	i;
	int	c;

	i = 0;
	c = len;
	while (i < c)
	{
		free(line[len - 1]);
		len--;
		i++;
		if (line == NULL)
			return ;
	}
	free(line);
}
