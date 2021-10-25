/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:08:41 by ji-park           #+#    #+#             */
/*   Updated: 2021/10/25 16:17:57 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_compt(int n, int fd)
{
	char	temp;

	if (n < 0 && n > -10)
		temp = (n * -1) + '0';
	else if (n < 0)
	{
		temp = ((n % 10) * -1) + '0';
		n = n / -10;
		ft_compt(n, fd);
	}
	else if (n >= 10)
	{
		temp = (n % 10) + '0';
		n = n / 10;
		ft_compt(n, fd);
	}
	else
		temp = n + '0';
	write(fd, &temp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_compt(n, fd);
}
