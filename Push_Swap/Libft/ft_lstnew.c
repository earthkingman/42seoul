/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:11:15 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/16 21:51:43 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	if ((new_list = (t_list *)malloc(sizeof(t_list))) == 0)
		return (0);
	new_list->content = content;
	new_list->next = 0;
	return (new_list);
}
