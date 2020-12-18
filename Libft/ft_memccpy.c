/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:26:17 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/06 22:37:12 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;
	unsigned char	c2;

	i = 0;
	c2 = (unsigned char)c;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (i < n)
	{
		if (src2[i] == c2)
		{
			dest2[i] = c2;
			return (&dest[i + 1]);
		}
		dest2[i] = src2[i];
		i++;
	}
	return (0);
}
