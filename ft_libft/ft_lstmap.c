/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:39:48 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/16 00:44:52 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*copy;
	t_list	*boop;

	if (!lst)
		return (NULL);
	element = ft_lstnew(f(lst->content));
	if (!element)
		return (NULL);
	copy = element;
	boop = lst->next;
	while (boop != NULL)
	{
		copy->next = ft_lstnew(f(boop->content));
		if (!(copy))
		{
			ft_lstclear(&element, del);
			return (NULL);
		}
		boop = boop->next;
		copy = copy->next;
	}
	return (element);
}
