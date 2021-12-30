/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:15:12 by asanthos          #+#    #+#             */
/*   Updated: 2021/12/13 17:43:24 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_initialize(t_m_struct *boop)
{
	if (ft_strcmp(boop->str, "julia") == 0)
		hmph(boop);
	else
	{
		boop->comp_c.real = 0.0;
		boop->comp_c.imag = 0.0;
	}
	boop->coord.depth_1 = 0x39ff14;
	boop->coord.temp_d = 0xAB32BF;
	boop->coord.iter = 10;
	boop->coord.size = 275;
}

void	win_init(t_m_struct *boop)
{
	boop->t_data.mlx_ptr = mlx_init();
	boop->t_data.win_ptr = mlx_new_window(boop->t_data.mlx_ptr,
			WIDTH, HEIGHT, "fractol");
	boop->i_data.img = mlx_new_image(boop->t_data.mlx_ptr, WIDTH, HEIGHT);
	boop->i_data.addr = mlx_get_data_addr(boop->i_data.img, &boop->i_data.bits,
			&boop->i_data.line_len, &boop->i_data.endian);
}

void	check_fractal(t_m_struct *boop)
{
	if (ft_strcmp(boop->str, "mandelbrot") == 0 || ft_strcmp(boop->str, "julia")
		== 0 || ft_strcmp(boop->str, "mandelbar") == 0
		|| ft_strcmp(boop->str, "burning ship") == 0)
		win_init(boop);
	else
	{
		printf("\nPlease enter one of the following fractal names");
		printf(":\nmandelbrot\njulia (x-value) (y-value)");
		printf("\nmandelbar\nburning ship\nburning ship 2\nlala\n\n");
	}
}

int	main(int argc, char **argv)
{
	t_m_struct	boop;

	if (argc == 2 || (argc == 4 && (ft_strcmp(argv[1], "julia") == 0)))
	{
		boop.str = argv[1];
		boop.str1 = argv[2];
		boop.str2 = argv[3];
		ft_initialize(&boop);
		check_fractal(&boop);
		draw_fractal(&boop);
		mlx_hook(boop.t_data.win_ptr, 2, 3, ft_key_hook, &boop);
		mlx_hook(boop.t_data.win_ptr, 4, 3, mouse_hook, &boop);
		mlx_loop(boop.t_data.mlx_ptr);
	}
	else
	{
		printf("\nPlease enter one of the following fractal names");
		printf(":\nmandelbrot\njulia (x-value) (y-value)");
		printf("\nmandelbar\nburning ship\nburning ship 2\nlala\n\n");
	}
	return (0);
}
