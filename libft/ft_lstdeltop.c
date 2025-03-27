/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeltop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:26:30 by nhendrik          #+#    #+#             */
/*   Updated: 2025/01/27 19:37:14 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_lstdeltop(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	(*lst)->content = 0;
	*lst = (*lst)->next;
	free(((*lst)->prev));
	(*lst)->prev = NULL;
}