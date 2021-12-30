/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:00:02 by asanthos          #+#    #+#             */
/*   Updated: 2021/12/14 18:52:29 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	fractal(t_m_struct *boop)
{
	if (ft_strcmp(boop->str, "mandelbrot") == 0)
		mandelbrot(boop);
	else if (ft_strcmp(boop->str, "julia") == 0)
		julia(boop);
	else if (ft_strcmp(boop->str, "mandelbar") == 0)
		mandelbar(boop);
	else if (ft_strcmp(boop->str, "burning ship") == 0)
		burning_ship(boop);
	else
		exit(EXIT_FAILURE);
}

void	draw_fractal(t_m_struct *boop)
{
	boop->coord.x = 0;
	while (boop->coord.x < WIDTH)
	{
		boop->coord.y = 0;
		while (boop->coord.y < HEIGHT)
		{
			fractal(boop);
			put_pixel(boop);
			boop->coord.y++;
		}
		boop->coord.x++;
	}
	mlx_put_image_to_window(boop->t_data.mlx_ptr,
		boop->t_data.win_ptr, boop->i_data.img, 0, 0);
}

void	mandelbrot(t_m_struct *boop)
{
	boop->comp_z.real = 0;
	boop->comp_z.imag = 0;
	boop->comp_c.imag = 2 - ((boop->coord.y + boop->coord.tmp_y)
			/ boop->coord.size);
	boop->comp_c.real = -2 + ((boop->coord.x + boop->coord.tmp_x)
			/ boop->coord.size);
	boop->coord.i = 0;
	while (boop->coord.i < boop->coord.iter
		&& (pow(boop->comp_z.real, 2) + pow(boop->comp_z.imag, 2) < 4))
	{
		boop->coord.temp = pow(boop->comp_z.real, 2)
			- pow(boop->comp_z.imag, 2) + boop->comp_c.real;
		boop->comp_z.imag = (2 * boop->comp_z.real
				* boop->comp_z.imag) + boop->comp_c.imag;
		boop->comp_z.real = boop->coord.temp;
		boop->coord.i++;
	}
}

void	hmph(t_m_struct *boop)
{
	if (boop->str1 && boop->str2)
	{
		if (ft_atof(boop->str1) > -2 && ft_atof(boop->str1) < 2
			&& ft_atof(boop->str2) > -2 && ft_atof(boop->str2) < 2)
		{
			boop->comp_c.imag = ft_atof(boop->str1);
			boop->comp_c.real = ft_atof(boop->str2);
		}
	}
	else
	{
		printf("input values");
		exit(EXIT_FAILURE);
	}
}

void	julia(t_m_struct *boop)
{
	boop->coord.i = 0;
	boop->comp_z.real = -2 + ((boop->coord.x + boop->coord.tmp_x)
			/ boop->coord.size);
	boop->comp_z.imag = 2 - ((boop->coord.y + boop->coord.tmp_y)
			/ boop->coord.size);
	while (boop->coord.i < boop->coord.iter
		&& (pow(boop->comp_z.real, 2) + pow(boop->comp_z.imag, 2) < 4))
	{
		boop->coord.temp = pow(boop->comp_z.real, 2)
			- pow(boop->comp_z.imag, 2) + boop->comp_c.real;
		boop->comp_z.imag = (2 * boop->comp_z.real * boop->comp_z.imag)
			+ boop->comp_c.imag;
		boop->comp_z.real = boop->coord.temp;
		boop->coord.i++;
	}
}
