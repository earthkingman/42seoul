/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prin_comb2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 19:42:28 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/06 12:49:11 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int a, int b)
{
	char arr[8];

	arr[0] = a / 10 + '0';
	arr[1] = a % 10 + '0';
	arr[2] = ' ';
	arr[3] = b / 10 + '0';
	arr[4] = b % 10 + '0';
	arr[5] = ',';
	arr[6] = ' ';
	if (arr[0] == '9' && arr[1] == '8')
		write(1, arr, 5);
	else
		write(1, arr, 7);
}

void	ft_print_comb2(void)
{
	int number[2];

	number[0] = 0;
	while (number[0] < 99)
	{
		number[1] = number[0] + 1;
		while (number[1] < 100)
		{
			ft_print(number[0], number[1]);
			number[1]++;
		}
		number[0]++;
	}
}
