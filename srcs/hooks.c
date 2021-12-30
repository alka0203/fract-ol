/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:27:29 by asanthos          #+#    #+#             */
/*   Updated: 2021/12/10 17:43:07 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	win_recreate(t_m_struct *boop)
{
	mlx_destroy_image(boop->t_data.mlx_ptr, boop->i_data.img);
	boop->i_data.img = mlx_new_image(boop->t_data.mlx_ptr, WIDTH, HEIGHT);
	mlx_clear_window(boop->t_data.mlx_ptr, boop->t_data.win_ptr);
	draw_fractal(boop);
}

int	ft_key_hook(int keycode, t_m_struct	*boop)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(boop->t_data.mlx_ptr, boop->t_data.win_ptr);
		exit(EXIT_FAILURE);
	}
	else if (keycode == KEY_PLUS)
		boop->coord.size *= 1.25;
	else if (keycode == KEY_MINUS)
		boop->coord.size /= 1.25;
	else if (keycode == KEY_I)
		boop->coord.iter += 5;
	else if (keycode == KEY_U)
		boop->coord.iter -= 5;
	else if (keycode == KEY_RIGHT)
		boop->coord.tmp_x += 200;
	else if (keycode == KEY_LEFT)
		boop->coord.tmp_x -= 200;
	else if (keycode == KEY_UP)
		boop->coord.tmp_y -= 200;
	else if (keycode == KEY_DOWN)
		boop->coord.tmp_y += 200;
	else if (keycode == KEY_A)
		boop->coord.temp_d += 0x02;
	win_recreate(boop);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_m_struct *boop)
{
	(void)x;
	(void)y;
	if (button == BTN_UP)
		boop->coord.size += 20;
	else if (button == BTN_DOWN)
		boop->coord.size -= 20;
	win_recreate(boop);
	return (0);
}
