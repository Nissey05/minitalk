/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:51:21 by nhendrik          #+#    #+#             */
/*   Updated: 2025/02/16 16:25:22 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (new->next && new->prev)
	{
		new->next->prev = new->prev;
		new->prev->next = new->next;
	}
	else if (new->next)
		new->next->prev = NULL;
	else if (new->prev)
		new->prev->next = NULL;
	end = ft_lstlast(*lst);
	end->next = new;
	new->prev = end;
	new->next = NULL;
	new->head = (*lst)->head;
}
