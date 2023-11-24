/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:05:41 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/05 11:05:57 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!del || !lst || !(*lst))
		return ;
	if ((*lst)->next)
		ft_lstclear((&(*lst)->next), del);
	(*del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}
