/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:56:35 by ji-park           #+#    #+#             */
/*   Updated: 2021/06/21 20:44:32 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	integer_conversion(char *argv, t_node **a, char **s)
{
	int		minus;
	int		i;
	long	number;

	minus = 1;
	i = 0;
	number = 0;
	if (argv[i] == '-')
	{
		minus = -1;
		i++;
	}
	if (!(argv[i] >= '0' && argv[i] <= '9'))
		print_error(a, 0, s);
	while (argv[i] != 0)
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			number = (number * 10) + (argv[i] - '0');
		i++;
	}
	number = number * minus;
	if (number < -2147483648 || number > 2147483648)
		print_error(a, 0, s);
	return (number);
}

int		duplicate_check(t_record *r, t_node **a, int value)
{
	t_node *temp;

	temp = *a;
	while (temp != r->check_overlap)
	{
		if (value == temp->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_split_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		free(s[i]);
	free(s[i]);
	free(s);
}

void	print_error(t_node **a, t_node **b, char **s)
{
	int i;

	if (a != 0)
		free_stack(a);
	if (b != 0)
		free_stack(b);
	if (s != 0)
	{
		i = -1;
		while (s[++i] != 0)
			free(s[i]);
		free(s[i]);
		free(s);
	}
	write(2, "Error\n", 6);
	exit(0);
}
