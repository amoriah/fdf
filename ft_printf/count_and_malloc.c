/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:13:51 by amoriah           #+#    #+#             */
/*   Updated: 2022/02/01 17:36:39 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conversion(unsigned long long i, char *str, int count)
{
	char	*set;

	set = "0123456789ABCDEF";
	while (count--)
	{
		str[count] = set[i % 16];
		i /= 16;
	}
	return (str);
}

char	*count_and_malloc(unsigned long long int i)
{
	int						count;
	char					*str;
	unsigned long long int	copy_i;

	count = 0;
	copy_i = i;
	if (i == 0)
		return (ft_strdup1("0"));
	while (copy_i)
	{
		copy_i /= 16;
		count++;
	}
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	str = conversion(i, str, count);
	return (str);
}
