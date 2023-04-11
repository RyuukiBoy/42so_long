/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:26:06 by oait-bad          #+#    #+#             */
/*   Updated: 2022/11/12 14:26:06 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_low(unsigned int n, int *len)
{
	char	*i;

	i = "0123456789abcdef";
	if (n < 16)
		ft_putchar(i[n], len);
	else
	{
		ft_puthexa_low(n / 16, len);
		ft_putchar(i[n % 16], len);
	}
}
