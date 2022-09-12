/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:17:18 by amoriah           #+#    #+#             */
/*   Updated: 2021/11/02 12:40:34 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(int c, va_list *argv)
{
	int		len;
	char	sym;

	len = 0;
	if (c == 'c')
	{
		sym = (unsigned char)va_arg(*argv, int);
		len += write(1, &sym, 1);
	}
	else if (c == 's')
		len += ft_putstr(va_arg(*argv, char *));
	else if (c == 'p')
		len += ft_putpointer(va_arg(*argv, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putdecimal(va_arg(*argv, int));
	else if (c == 'u')
		len += ft_putunsig(va_arg(*argv, unsigned int));
	else if (c == 'x')
		len += ft_puthex(va_arg(*argv, unsigned int), 1);
	else if (c == 'X')
		len += ft_puthex(va_arg(*argv, unsigned int), 0);
	return (len);
}
