/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:26:32 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/19 18:39:45 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *curr;

	if (lst == 0 || f == 0)
		return ;
	curr = lst;
	while (curr)
	{
		f(curr->content);
		curr = curr->next;
	}
}
