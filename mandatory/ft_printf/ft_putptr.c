/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:26:23 by oait-bad          #+#    #+#             */
/*   Updated: 2022/11/12 14:26:23 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long n, int *len, int f)
{
	char	*i;

	i = "0123456789abcdef";
	if (f)
		ft_putstr("0x", len);
	if (n < 16)
		ft_putchar(i[n], len);
	else
	{
		ft_putptr(n / 16, len, 0);
		ft_putchar(i[n % 16], len);
	}
}
