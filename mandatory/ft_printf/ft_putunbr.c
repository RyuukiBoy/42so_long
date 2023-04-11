/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:54:58 by oait-bad          #+#    #+#             */
/*   Updated: 2022/11/12 19:20:04 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int n, int *len)
{
	if (n >= 0 && n <= 9)
	{	
		ft_putchar(n + '0', len);
	}
	else if (n >= 10)
	{	
		ft_putunbr(n / 10, len);
		ft_putunbr(n % 10, len);
	}
}
