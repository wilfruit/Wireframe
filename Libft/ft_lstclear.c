/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:27:16 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/02 17:21:38 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void*))
{
	t_list	*tmp;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		tmp = *alst;
		(*del)((*alst)->content);
		*alst = (*alst)->next;
		free(tmp);
	}
	*alst = 0;
}
