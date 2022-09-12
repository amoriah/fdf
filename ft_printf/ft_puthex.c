/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:58:50 by amoriah           #+#    #+#             */
/*   Updated: 2022/03/09 17:45:35 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_case(char *str);

int	ft_puthex(size_t i, int low)
{
	char	*str;
	size_t	copy_i;
	int		len;

	len = 0;
	copy_i = i;
	if (i == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	len = 0;
	str = count_and_malloc(copy_i);
	if (low == 1)
		str = ft_case(str);
	len += ft_putstr(str);
	free(str);
	return (len);
}
