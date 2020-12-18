/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:54:53 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/06 19:59:51 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (j == 0 && str[i] > 96 && str[i] < 123)
		{
			str[i] = str[i] - 32;
		}
		else if (j != 0 && str[i] > 64 && str[i] < 91)
		{
			str[i] = str[i] + 32;
		}
		else if (str[i] >= 91 && str[i] <= 96)
			j = -1;
		else if (str[i] <= 47 || str[i] >= 123)
			j = -1;
		else if (str[i] >= 58 && str[i] <= 64)
			j = -1;
		j++;
		i++;
	}
	return (str);
}
