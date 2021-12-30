/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:33:17 by asanthos          #+#    #+#             */
/*   Updated: 2021/12/10 18:55:41 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_m_struct *boop)
{
	boop->coord.dst = boop->i_data.addr + (boop->coord.y
			* boop->i_data.line_len + boop->coord.x * (boop->i_data.bits / 8));
	if (boop->coord.i < boop->coord.iter)
	{
		boop->coord.depth_1 = 0x32bb14;
		while (boop->coord.i-- >= 0)
		{
			boop->coord.depth_1 *= boop->coord.temp_d;
			boop->coord.j = boop->coord.i;
			boop->coord.depth_2 = boop->coord.depth_1;
			while (boop->coord.j-- >= boop->coord.i - 3)
			{
				boop->coord.k = boop->coord.j;
				boop->coord.depth_3 = boop->coord.depth_2;
				while (boop->coord.k >= boop->coord.j - 3)
				{
					*(unsigned int *)boop->coord.dst = boop->coord.depth_3;
					boop->coord.k--;
					boop->coord.depth_3 -= 0x03;
				}
				boop->coord.depth_2 *= (0xB0E0E6 / 20);
			}
			boop->coord.depth_1 /= 2;
		}
	}
}
