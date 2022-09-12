/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:22:12 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/13 12:00:15 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	check_alloc(int **a)
{
	if (!a)
	{
		perror(ERR);
		exit (EXIT_FAILURE);
	}
}

void	check_fd(int i)
{
	if (i == -1)
	{
		perror(ERR);
		exit (EXIT_FAILURE);
	}
}

void	check_struct(t_fdf *data)
{
	if (data == NULL)
	{
		perror(ERR);
		exit(EXIT_FAILURE);
	}
}
