/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:31:10 by oait-bad          #+#    #+#             */
/*   Updated: 2022/11/22 18:14:00 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)

{	
	if (n == -2147483648)
	{	
		ft_putstr("-2147483648", len);
	}
	else
	{	
		if (n >= 0 && n <= 9)
		{	
			ft_putchar(n + '0', len);
		}
		if (n < 0)
		{	
			ft_putchar('-', len);
			ft_putnbr(n * -1, len);
		}
		if (n >= 10)
		{	
			ft_putnbr(n / 10, len);
			ft_putnbr(n % 10, len);
		}
	}
}
