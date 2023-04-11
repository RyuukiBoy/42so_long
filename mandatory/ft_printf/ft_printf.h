/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:47:25 by oait-bad          #+#    #+#             */
/*   Updated: 2022/11/12 22:48:03 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

void	ft_putchar(char n, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putunbr(unsigned int n, int *len);
void	ft_putptr(unsigned long n, int *len, int f);
void	ft_puthexa_low(unsigned int n, int *len);
void	ft_puthexa_upp(unsigned int n, int *len);
int		ft_printf(const char *str, ...);

#endif