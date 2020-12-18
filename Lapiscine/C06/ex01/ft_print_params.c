/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:34:54 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/13 16:59:22 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		length(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		len;

	i = 1;
	while (i < argc)
	{
		len = length(argv[i]);
		write(1, &argv[i][0], len);
		write(1, "\n", 1);
		i++;
	}
}
