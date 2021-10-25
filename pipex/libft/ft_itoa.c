/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:14:18 by ji-park           #+#    #+#             */
/*   Updated: 2021/10/25 16:06:55 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(int n, char *str, size_t count)
{
	if (n < 0)
	{
		str[0] = '-';
		count++;
	}
	str[count] = '\0';
	if (n < 0)
	{
		while (--count)
		{
			str[count] = ((n % -10) * -1) + '0';
			n = n / 10;
		}
	}
	else
	{
		while (count--)
		{
			str[count] = (n % 10) + '0';
			n = n / 10;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		temp;
	int		count;
	int		sign;

	if (n != 0 && !n)
		return (NULL);
	sign = 0;
	if (n < 0)
		sign = 1;
	count = 0;
	if (n == 0)
		count = 1;
	temp = n;
	while (temp)
	{
		temp = temp / 10;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (sign + count + 1));
	if (!str)
		return (NULL);
	str = ft_convert(n, str, count);
	return (str);
}
