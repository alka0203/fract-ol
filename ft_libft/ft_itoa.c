/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:55:45 by asanthos          #+#    #+#             */
/*   Updated: 2021/12/05 16:42:12 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	ft_len(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (12);
	if (n == 0)
		return (2);
	while (n < 0 || n == 0)
	{
		n *= -1;
		i++;
	}
	while (n != '\0')
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char	*mall(int n)
{
	int		len;
	char	*s;

	len = ft_len(n);
	s = (char *)malloc(len);
	if (!s)
		return (NULL);
	s[len - 1] = '\0';
	return ((char *)s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;

	s = mall(n);
	len = ft_len(n) - 1;
	if (!s)
		return (NULL);
	if (n == 0)
		s[--len] = n + 48;
	if (n == -2147483648)
	{
		s[--len] = '8';
		n = -214748364;
	}
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n)
	{
		s[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}
