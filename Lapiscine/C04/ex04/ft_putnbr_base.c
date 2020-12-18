/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 09:46:09 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/11 21:56:55 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_valid(char *base)
{
	int		i;
	int		k;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		k = i + 1;
		while (base[k] != '\0')
		{
			if (base[i] == base[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	p_recursive(int n, char *base, int len)
{
	int i;

	i = n % len;
	if (n / len != 0)
	{
		p_recursive(n / len, base, len);
	}
	write(1, &base[i], 1);
}

void	m_recursive(int n, char *base, int len)
{
	int i;

	i = -1 * (n % len);
	if (n / len != 0)
	{
		m_recursive(n / len, base, len);
	}
	write(1, &base[i], 1);
}

int		check_length(char *a)
{
	int i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;

	if (!base_valid(base))
		return ;
	len = check_length(base);
	if (nbr >= 0)
		p_recursive(nbr, base, len);
	else
	{
		write(1, "-", 1);
		m_recursive(nbr, base, len);
	}
}
