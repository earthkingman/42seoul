/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:28:51 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/21 18:59:33 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_num(const char *str, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && str[i] != 0)
		{
			num++;
			while (str[i] != c && str[i] != 0)
				i++;
		}
		else if (str[i] != 0)
			i++;
	}
	return (num);
}

static	void	*free_mem(char **allocated_mem, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(allocated_mem[i]);
		i++;
	}
	free(allocated_mem);
	return (NULL);
}

static	void	ft_strcpy(char *dst, char const *src, int start, int last)
{
	int i;

	i = 0;
	while (start < last)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = 0;
}

static	void	do_split(char const *s, char c, char **str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			start = i;
			while (s[i] != c && s[i] != 0)
				i++;
			if ((str[j] = (char *)malloc(sizeof(char) * (i - start + 1))) == 0)
			{
				free_mem(str, j);
				return ;
			}
			ft_strcpy(str[j], s, start, i);
			j++;
		}
		else if (s[i] != 0)
			i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	n;

	if (s == 0)
		return (0);
	n = get_num(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (str == 0)
		return (0);
	str[n] = 0;
	if (n == 0)
		return (str);
	do_split(s, c, str);
	return (str);
}
