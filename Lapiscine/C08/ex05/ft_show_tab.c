/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <gudor123@nate.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:18:42 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/20 15:53:45 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_int(int n)
{
	char a;

	a = (n % 10) + '0';
	if (n / 10 != 0)
		print_int(n / 10);
	write(1, &a, 1);
}

void	ft_show_tab(struct s_stock_str *node)
{
	int		i;

	i = 0;
	while (node[i].str != '\0')
	{
		print_str(node[i].str);
		print_int(node[i].size);
		write(1, "\n", 1);
		print_str(node[i].copy);
		i++;
	}
}
