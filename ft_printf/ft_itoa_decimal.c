/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:47:56 by amoriah           #+#    #+#             */
/*   Updated: 2022/02/01 17:36:29 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_number(ssize_t n)
{
	int	len_n;

	len_n = 0;
	while (n)
	{
		n = n / 10;
		len_n++;
	}
	return (len_n);
}

static char	*from_int_to_char(char *str, ssize_t n, int len)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	while (n)
	{
		str[len--] = n % 10 * sign + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa_decimal(ssize_t n)
{
	int		len;
	char	*str;

	len = len_number(n);
	if (n <= 0)
		len = len + 1;
	str = (char *)ft_calloc1((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	return (from_int_to_char(str, n, len));
}
