/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_errors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:23:32 by oait-bad          #+#    #+#             */
/*   Updated: 2023/04/08 13:35:22 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	invalid_map_b(void)
{
	ft_printf(KRED"Invalid Map !!\n");
	exit(1);
}

void	invalid_extension_b(void)
{
	ft_printf(KRED"Invalid File !!\n");
	exit(1);
}

void	invalid_items_b(void)
{
	ft_printf(KRED"Items Are Not Enough !!\n");
	exit(1);
}

void	put_msg_b(int n)
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
	else if (n == 2)
	{
		ft_printf(KRED"YOU LOST !!\n");
		exit(1);
	}
}

void	roadblock_msg_b(void)
{
	ft_printf(KRED"Roadblock !!\n");
	exit(1);
}
