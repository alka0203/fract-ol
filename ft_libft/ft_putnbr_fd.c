/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:56:22 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/17 04:10:29 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	void	ft_putchar(char x, int fd)
{
	write(fd, &x, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48, fd);
		return ;
	}
	else
		ft_putnbr_fd(nb / 10, fd);
	ft_putnbr_fd(nb % 10, fd);
}
