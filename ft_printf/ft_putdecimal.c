/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:57:17 by amoriah           #+#    #+#             */
/*   Updated: 2021/11/02 11:52:26 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdecimal(ssize_t i)
{
	char	*digit;
	int		len;

	len = 0;
	digit = ft_itoa_decimal(i);
	len += ft_putstr(digit);
	free(digit);
	return (len);
}
