/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:30:59 by nhendrik          #+#    #+#             */
/*   Updated: 2025/02/10 13:57:57 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstsethead(t_list **lst, t_list *head)
{
	t_list *start;

	if (*lst)
		start = (*lst);
	while(*lst)
	{
		(*lst)->head = head;
		(*lst) = (*lst)->next;
	}
	(*lst) = start;
}
