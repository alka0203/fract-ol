/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:25:20 by asanthos          #+#    #+#             */
/*   Updated: 2021/12/10 21:19:03 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 1080
# define WIDTH 1080
# define SIZE 275

# define KEYS_H
# define KEY_ESC			53
# define KEY_PLUS			24
# define KEY_MINUS			27
# define KEY_A				0
# define KEY_U				32
# define KEY_I				34
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_LEFT			123
# define KEY_FN				63
# define BTN_UP				4
# define BTN_DOWN			5

# include "../ft_libft/libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_coord
{
	int		x;
	int		y;
	double	temp;
	int		i;
	int		j;
	int		k;
	int		depth_1;
	int		depth_2;
	int		depth_3;
	int		temp_d;
	char	*dst;
	double	size;
	int		iter;
	int		tmp_x;
	int		tmp_y;
}			t_coord;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_data;

typedef struct s_img_data
{
	void	*img;
	int		bits;
	int		line_len;
	int		endian;
	char	*addr;
}			t_img_data;

typedef struct s_m_struct
{
	t_complex	comp_z;
	t_complex	comp_c;
	t_coord		coord;
	t_data		t_data;
	t_img_data	i_data;
	int			flag;
	char		*str;
	char		*str1;
	char		*str2;
}			t_m_struct;

void	draw_fractal(t_m_struct *boop);
void	mandelbrot(t_m_struct *boop);
void	mandelbar(t_m_struct *boop);
void	julia(t_m_struct *boop);
void	put_pixel(t_m_struct *boop);
void	ft_initialize(t_m_struct *boop);
int		ft_key_hook(int keycode, t_m_struct	*boop);
int		render_frame(char *str, t_m_struct *boop);
int		mouse_hook(int button, int x, int y, t_m_struct *boop);
void	check_fractal(t_m_struct *boop);
void	win_init(t_m_struct *boop);
void	burning_ship(t_m_struct *boop);
void	hmph(t_m_struct *boop);
int		main(int argc, char **argv);

#endif
