/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:13:32 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/07 15:27:13 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	invalid_map(void)
{
	ft_printf(KRED"Invalid Map !!\n");
	exit(1);
}

void	invalid_extension(void)
{
	ft_printf(KRED"Invalid File !!\n");
	exit(1);
}

void	invalid_items(void)
{
	ft_printf(KRED"Items Are Not Enough !!\n");
	exit(1);
}

void	put_msg(int n)
{
	if (n == 0)
	{
		ft_printf(KYEL"You Left The Game !!\n");
		exit(0);
	}
	else if (n == 1)
	{
		ft_printf(KGRN"CONGRATULATIONS , YOU WON GG !!\n");
		exit(0);
	}
}

void	roadblock_msg(void)
{
	ft_printf(KRED"Roadblock !!\n");
	exit(1);
}
