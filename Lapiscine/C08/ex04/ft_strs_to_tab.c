/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:57:38 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/20 16:11:22 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						get_length(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char					*ft_strdup(char *src)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = get_length(src);
	dest = (char *)malloc(sizeof(char) * n + 1);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str		*ft_strs_to_tab(int argc, char *argv[])
{
	t_stock_str		*arr;
	int				i;

	i = 0;
	if (!(arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (argc + 1))))
		return (0);
	while (i < argc)
	{
		arr[i].str = argv[i];
		arr[i].size = get_length(argv[i]);
		arr[i].copy = ft_strdup(argv[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}
