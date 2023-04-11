/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:04:07 by oait-bad          #+#    #+#             */
/*   Updated: 2022/11/22 20:24:39 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_sepc(va_list args, const char s, int *len)
{
	if (s == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (s == 's')
		ft_putstr(va_arg(args, char *), len);
	else if ((s == 'd' || s == 'i'))
		ft_putnbr(va_arg(args, int), len);
	else if (s == 'u')
		ft_putunbr(va_arg(args, unsigned int), len);
	else if (s == 'p')
		ft_putptr((unsigned long)va_arg(args, void *), len, 1);
	else if (s == 'x')
		ft_puthexa_low(va_arg(args, unsigned int), len);
	else if (s == 'X')
		ft_puthexa_upp(va_arg(args, unsigned int), len);
	else if (s == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format_sepc(args, str[i], &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
