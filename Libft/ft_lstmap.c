/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:16:18 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/02 19:22:14 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*modlst;
	t_list	*cursor;

	modlst = 0;
	if (!l || !f)
		return (0);
	while (l)
	{
		cursor = ft_lstnew((*f)(l->content));
		if (!cursor)
		{
			ft_lstclear(&modlst, d);
			return (0);
		}
		ft_lstadd_back(&modlst, cursor);
		l = l->next;
	}	
	return (modlst);
}
