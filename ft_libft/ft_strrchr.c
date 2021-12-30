/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:19:53 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/12 15:56:19 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	while (i + 1)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}
