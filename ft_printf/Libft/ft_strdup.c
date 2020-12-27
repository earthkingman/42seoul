/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:31:31 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/10 15:04:05 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	n;
	char	*newstr;

	i = pf_strlen(str);
	n = 0;
	newstr = (char *)malloc(sizeof(char) * (i + 1));
	if (newstr == 0)
		return (0);
	while (n < i)
	{
		newstr[n] = str[n];
		n++;
	}
	newstr[n] = 0;
	return (newstr);
}
