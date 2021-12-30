/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:26:56 by asanthos          #+#    #+#             */
/*   Updated: 2021/12/10 18:48:45 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	char	*dest;
	int		count;
	double	res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = (char *)malloc(ft_strlen(str));
	count = ft_strlen(str);
	while (str[i] != '.')
		dest[j++] = str[i++];
	count -= ft_strlen(dest);
	while (str[++i])
		dest[j++] = str[i];
	dest[i] = '\0';
	res = (double)ft_atoi(dest);
	while (--count)
		res /= 10;
	return (res);
}
