/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 20:09:12 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/16 16:27:26 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strcat(char *src1, char *src2)
{
	while (*src1)
		src1++;
	while (*src2)
	{
		*src1 = *src2;
		src2++;
		src1++;
	}
	*src1 = 0;
}

int		ft_len(char **strs, char *sep, int size)
{
	int count;
	int i;
	int j;

	i = 0;
	count = 0;
	while (sep[i])
		i++;
	count = count + (i * (size - 1));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			count = count + 1;
		}
		i++;
	}
	return (count + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		count;

	if (size == 0)
	{
		arr = (char *)malloc(1);
		arr[0] = 0;
		return (arr);
	}
	count = ft_len(strs, sep, size);
	arr = malloc(count * sizeof(char));
	arr[0] = 0;
	count = 0;
	while (count < size - 1)
	{
		ft_strcat(arr, strs[count]);
		ft_strcat(arr, sep);
		count++;
	}
	ft_strcat(arr, strs[count]);
	return (arr);
}
