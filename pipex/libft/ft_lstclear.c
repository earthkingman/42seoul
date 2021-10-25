/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:48:20 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/20 02:42:22 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *head;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		head = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = head;
	}
	*lst = 0;
}
