/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:55:33 by ji-park           #+#    #+#             */
/*   Updated: 2020/11/13 18:04:08 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *str)
{
	size_t		i;
	size_t		n;
	char		*newstr;

	i = ft_strlen(str);
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

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1 == 0 || s2 == 0)
		return (0);
	if ((str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))) == 0)
		return (0);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}
