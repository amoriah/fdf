/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:54:16 by amoriah           #+#    #+#             */
/*   Updated: 2022/02/01 17:36:16 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char	*count_and_malloc(unsigned long long int i);
void	*ft_calloc1(size_t count, size_t size);
char	*ft_itoa_decimal(ssize_t n);
int		ft_printf(const char *s, ...);
int		ft_putdecimal(ssize_t i);
int		ft_puthex(size_t i, int low);
int		ft_putpointer(void *num);
int		ft_putstr(char *str);
int		ft_putunsig(size_t i);
char	*ft_strdup1(const char *s1);
char	*ft_unsig_itoa(size_t n);
int		look_for_type(int c);
int		check_type(int c, va_list *argv);
#endif
