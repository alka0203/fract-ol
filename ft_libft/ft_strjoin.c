/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:11:53 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/16 00:17:02 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
		return (0);
	concat = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!concat)
		return (0);
	while (s1[i])
	{
		((char *)concat)[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j])
	{
		((char *)concat)[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}
