/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:57:27 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/13 21:12:50 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		cmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	return (0);
}

int		str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print(int argc, char *argv[])
{
	int i;
	int len;

	i = 1;
	while (i < argc)
	{
		len = str_len(argv[i]);
		write(1, &argv[i][0], len);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		max;
	int		i;
	int		j;
	char	*temp;

	i = 0;
	max = argc;
	while (i < max)
	{
		j = 1;
		while (j < max - 1 - i)
		{
			if (cmp(argv[j], argv[j + 1]) == 1)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	print(argc, argv);
	return (1);
}
