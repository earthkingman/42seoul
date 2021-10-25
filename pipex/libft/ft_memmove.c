/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:17:09 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/06 22:37:38 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	if (destination == source || num == 0)
		return (destination);
	i = 0;
	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (dest < src)
		while (i < num)
		{
			dest[i] = src[i];
			i++;
		}
	else
		while (i < num)
		{
			dest[num - i - 1] = src[num - i - 1];
			i++;
		}
	return (destination);
}
