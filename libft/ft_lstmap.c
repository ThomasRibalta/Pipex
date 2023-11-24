/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:12:32 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/05 13:02:56 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*global;

	if (!lst || !f || !del)
		return (NULL);
	global = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			new = global->next;
			(*del)(global->content);
			free(global);
			global = new;
			free(lst);
		}
		ft_lstadd_back(&global, new);
		lst = lst->next;
	}
	return (global);
}
