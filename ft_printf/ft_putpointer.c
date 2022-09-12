/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:02:09 by amoriah           #+#    #+#             */
/*   Updated: 2021/11/02 17:10:35 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_case(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

static int	check_pointer(unsigned long long int i)
{
	int	len;

	len = 0;
	if (!i)
	{
		write(1, "0", 1);
		return (len += 1);
	}
	else
		return (len);
}

int	ft_putpointer(void *num)
{
	int						len;
	char					*str;
	unsigned long long int	i;

	len = 0;
	i = (unsigned long long int)num;
	len += check_pointer(i);
	if (len > 0)
	{
		len += write(1, "x0", 2);
		return (len);
	}
	str = count_and_malloc(i);
	str = ft_case(str);
	len += write(1, "0x", 2);
	len += ft_putstr(str);
	free(str);
	return (len);
}
