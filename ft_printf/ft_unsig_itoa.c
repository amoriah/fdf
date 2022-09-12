/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:35:15 by amoriah           #+#    #+#             */
/*   Updated: 2022/02/01 17:35:28 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_number(size_t n)
{
	unsigned int	len_n;

	len_n = 0;
	while (n)
	{
		n = n / 10;
		len_n++;
	}
	return (len_n);
}

static char	*from_int_to_char(char *str, size_t n, int len)
{
	while (n)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_unsig_itoa(size_t n)
{
	unsigned int		len;
	char				*str;

	len = len_number(n);
	if (n == 0)
		len = len + 1;
	str = (char *)ft_calloc1((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	return (from_int_to_char(str, n, len));
}
