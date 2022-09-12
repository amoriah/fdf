/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:18:01 by amoriah           #+#    #+#             */
/*   Updated: 2021/11/02 12:48:19 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parsing(const char *s, va_list *argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%' && s[i])
			len += write(1, &s[i++], 1);
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == '%')
				len += write(1, &s[i], 1);
			else if (look_for_type(s[i]))
				len += check_type(s[i], argv);
			else if (s[i])
				len += write(1, &s[i], 1);
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	argv;
	int		lenght;

	if (!s)
		return (-1);
	va_start(argv, s);
	lenght = parsing(s, &argv);
	va_end(argv);
	return (lenght);
}
