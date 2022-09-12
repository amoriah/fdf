/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:09:22 by amoriah           #+#    #+#             */
/*   Updated: 2021/11/02 11:57:04 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsig(size_t i)
{
	char				*digit;
	unsigned int		copy_i;
	int					len;

	copy_i = i;
	len = 0;
	digit = ft_unsig_itoa(copy_i);
	len += ft_putstr(digit);
	free(digit);
	return (len);
}
