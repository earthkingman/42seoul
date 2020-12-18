/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:32:22 by ji-park           #+#    #+#             */
/*   Updated: 2020/08/13 17:16:35 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		main(int argc, char *argv[])
{
	int i;
	int l;

	i = argc - 1;
	while (i > 0)
	{
		l = len(argv[i]);
		write(1, &argv[i][0], l);
		write(1, "\n", 1);
		i--;
	}
}
