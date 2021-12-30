/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:42:15 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/03 01:23:38 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int		i;
	unsigned char		*dest;

	i = 0;
	dest = (unsigned char *)b;
	while (i < len)
	{
		dest[i] = c;
		i++;
	}
	return (b);
}
