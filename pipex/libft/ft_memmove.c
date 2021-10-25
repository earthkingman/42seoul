/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 18:17:09 by ji-park           #+#    #+#             */
/*   Updated: 2021/10/25 16:09:17 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*uc_dst;
	const unsigned char	*uc_src;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	uc_dst = (unsigned char *)dst;
	uc_src = (unsigned char *)src;
	if (dst <= src)
	{
		i = 0;
		while (i < len)
		{
			uc_dst[i] = uc_src[i];
			i++;
		}
	}
	else
		while (len--)
			uc_dst[len] = uc_src[len];
	return (dst);
}
