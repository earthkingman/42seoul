/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:29:34 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/06 12:57:09 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *number, int size)
{
	char	a[2];
	int		temp;

	temp = 10 - size;
	a[0] = ',';
	a[1] = ' ';
	write(1, number, size);
	if (!(number[size - 1] == '9' && number[0] == (temp + '0')))
		write(1, a, 2);
}

void	roop(int index, char *arr, int size)
{
	int i;

	if (size == index)
	{
		print(arr, size);
	}
	else
	{
		if (index == 0)
			i = 0;
		else
			i = arr[index - 1] - 48 + 1;
		while (i < 10)
		{
			arr[index] = i + '0';
			roop(index + 1, arr, size);
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[n];

	roop(0, arr, n);
}
