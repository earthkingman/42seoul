/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:34:59 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/19 22:35:01 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*curr;
	t_list	*temp;

	if (lst == 0 || f == 0)
		return (0);
	if ((newlst = ft_lstnew(f(lst->content))) == 0)
		return (0);
	curr = newlst;
	lst = lst->next;
	while (lst)
	{
		if ((temp = ft_lstnew(f(lst->content))) == 0)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		curr->next = temp;
		curr = temp;
		lst = lst->next;
	}
	return (newlst);
}
