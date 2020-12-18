/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:02:45 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/16 18:11:31 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int number;

	number = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		number *= nb;
		power--;
	}
	return (number);
}
