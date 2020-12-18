/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 19:38:17 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/06 12:47:40 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char digit[6];

	digit[0] = '0';
	digit[3] = ',';
	digit[4] = ' ';
	while (digit[0] <= '7')
	{
		digit[1] = digit[0] + 1;
		while (digit[1] <= '8')
		{
			digit[2] = digit[1] + 1;
			while (digit[2] <= '9')
			{
				if (digit[0] == '7')
					write(1, &digit[0], 3);
				else
					write(1, &digit[0], 5);
				digit[2]++;
			}
			digit[1]++;
		}
		digit[0]++;
	}
}
