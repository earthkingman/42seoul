/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:56:01 by ji-park           #+#    #+#             */
/*   Updated: 2021/10/25 16:20:50 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == (char)ch)
			return ((char *)&str[i]);
		i++;
	}
	if (ch == 0)
		return ((char *)&str[i]);
	return (0);
}
