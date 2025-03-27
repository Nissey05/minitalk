/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:45:29 by nhendrik          #+#    #+#             */
/*   Updated: 2025/02/11 22:01:16 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
		{
		if ((*lst) != new)
		{
			if (new->next && new->prev)
			{
				new->next->prev = new->prev;
				new->prev->next = new->next;
			}
			else if (new->next)
				new->next->prev = NULL;
			else if (new->prev)
				new->prev->next = NULL;
			new->next = *lst;
			new->prev = NULL;
			if (*lst)
				(*lst)->prev = new;
			*lst = new;
		}
	}
}
