/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:37:48 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/06 20:01:40 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	get_hex(int n)
{
	if (n < 10)
		return (n + 48);
	return (n + 87);
}

void	print(unsigned char c)
{
	unsigned char asci;

	write(1, "\\", 1);
	asci = get_hex(c / 16);
	write(1, &asci, 1);
	asci = get_hex(c % 16);
	write(1, &asci, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			print(str[i]);
		i++;
	}
}
