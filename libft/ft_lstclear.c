/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:52:01 by nhendrik          #+#    #+#             */
/*   Updated: 2025/01/27 20:21:47 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buff;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		buff = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = buff;
	}
	del(buff);
	*lst = NULL;
}