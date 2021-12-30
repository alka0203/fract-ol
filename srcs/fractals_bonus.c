/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:02:58 by asanthos          #+#    #+#             */
/*   Updated: 2021/12/10 19:42:18 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burning_ship(t_m_struct *boop)
{
	boop->comp_z.real = 0;
	boop->comp_z.imag = 0;
	boop->comp_c.imag = -2 + ((boop->coord.y + boop->coord.tmp_y)
			/ boop->coord.size);
	boop->comp_c.real = 2 - ((boop->coord.x + boop->coord.tmp_x)
			/ boop->coord.size);
	boop->coord.i = 0;
	while (boop->coord.i < boop->coord.iter && pow(boop->comp_z.real, 2)
		+ pow(boop->comp_z.imag, 2) < 4)
	{
		boop->coord.temp = pow(fabs(boop->comp_z.real), 2)
			- pow(fabs(boop->comp_z.imag), 2) + boop->comp_c.real;
		boop->comp_z.imag = (2 * fabs(boop->comp_z.real)
				* fabs(boop->comp_z.imag)) + boop->comp_c.imag;
		boop->comp_z.real = boop->coord.temp;
		boop->coord.i++;
	}
}

void	mandelbar(t_m_struct *boop)
{
	boop->comp_z.real = 0;
	boop->comp_z.imag = 0;
	boop->comp_c.imag = 2 - ((boop->coord.y + boop->coord.tmp_y)
			/ boop->coord.size);
	boop->comp_c.real = -2 + ((boop->coord.x + boop->coord.tmp_x)
			/ boop->coord.size);
	boop->coord.i = 0;
	while (boop->coord.i < boop->coord.iter && (pow(boop->comp_z.real, 2)
			+ pow(boop->comp_z.imag, 2) < 4))
	{
		boop->coord.temp = pow(boop->comp_z.real, 2)
			- pow(boop->comp_z.imag, 2) + boop->comp_c.real;
		boop->comp_z.imag = (-2 * boop->comp_z.real * boop->comp_z.imag)
			+ boop->comp_c.imag;
		boop->comp_z.real = boop->coord.temp;
		boop->coord.i++;
	}
}
