/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 20:57:59 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/06 22:36:48 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	if (!destination && !source)
		return (0);
	src = (unsigned char *)source;
	dest = (unsigned char *)destination;
	i = 0;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return (destination);
}
