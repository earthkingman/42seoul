/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:53:17 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/17 14:42:57 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*curr;

	if (lst == 0 || new_node == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new_node;
		return ;
	}
	curr = *lst;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}
