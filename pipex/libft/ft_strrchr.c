/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:04:31 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/09 15:50:50 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	const char	*last;
	int			i;

	i = 0;
	last = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)ch)
			last = &s[i];
		i++;
	}
	if (ch == 0)
		return ((char *)&s[i]);
	return ((char *)last);
}
