/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:14:18 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/20 02:43:17 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_len(long long n)
{
	size_t			i;

	i = 0;
	if (n < 0)
		n = n * -1;
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	void		do_itoa(unsigned int tmp, char *str, int len)
{
	while (tmp > 0)
	{
		str[len--] = (tmp % 10) + 48;
		tmp = tmp / 10;
	}
}

char				*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	tmp;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_len(n);
	if (n < 0)
	{
		tmp = n * -1;
		len++;
	}
	else
		tmp = n;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	str[len] = 0;
	len--;
	if (n < 0)
		str[0] = '-';
	do_itoa(tmp, str, len);
	return (str);
}
