/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:06:04 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/06 23:48:42 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t cnt;
	size_t i;

	cnt = 0;
	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[cnt] != 0)
		cnt++;
	if (size != 0)
	{
		while (src[i] != 0 && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (cnt);
}
