/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 21:12:47 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/18 11:56:16 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		next_prime(int nb)
{
	int i;
	int nbr;

	if (nb <= 1)
		return (0);
	i = 2;
	nbr = nb / 2;
	while (i <= nbr && i <= 65536)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (next_prime(nb) == 0)
		nb++;
	return (nb);
}
