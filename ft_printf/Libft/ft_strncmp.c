/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:31:12 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/09 20:09:27 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *str1, char *str2, size_t num)
{
	size_t i;

	i = 0;
	while ((str1[i] != 0 || str2[i] != 0) && i < num)
	{
		if (str1[i] > str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		else if (str1[i] < str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	if (num == 0)
		return (0);
	return (0);
}
