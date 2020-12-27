/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:23:07 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/06 18:51:24 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	char			*start_ptr;
	unsigned char	data;

	start_ptr = (char*)ptr;
	data = (unsigned char)value;
	i = 0;
	while (num--)
	{
		start_ptr[i++] = data;
	}
	return (ptr);
}
