/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 01:35:22 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/02 21:28:11 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	unsigned int	i;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
