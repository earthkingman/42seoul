/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:08:41 by ji-park           #+#    #+#             */
/*   Updated: 2020/10/20 02:44:02 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	plus_putnbr(int n, int fd)
{
	char a;

	a = (n % 10) + 48;
	if (n / 10 != 0)
	{
		plus_putnbr(n / 10, fd);
	}
	write(fd, &a, 1);
}

static	void	minus_putnbr(int n, int fd)
{
	char a;

	a = -1 * (n % 10) + 48;
	if (n / 10 != 0)
	{
		minus_putnbr(n / 10, fd);
	}
	write(fd, &a, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
		plus_putnbr(n, fd);
	else if (n < 0)
	{
		write(fd, "-", 1);
		minus_putnbr(n, fd);
	}
	else if (n == 0)
		write(fd, "0", 1);
}
