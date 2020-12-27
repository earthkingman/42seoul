/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:38:30 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/10 12:26:01 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = pf_strlen(s1);
	s2_len = pf_strlen(s2);
	if ((str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))) == 0)
		return (0);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j != s2_len)
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
