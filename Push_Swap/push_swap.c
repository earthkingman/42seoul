/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:56:32 by ji-park           #+#    #+#             */
/*   Updated: 2021/06/21 20:44:32 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_record *r, t_node **a, int value)
{
	t_node		*node;
	t_node		*bottom;

	if (r->max < value)
		r->max = value;
	if (r->min > value)
		r->min = value;
	node = (t_node *)malloc(sizeof(t_node));
	node->value = value;
	node->next = 0;
	bottom = *a;
	if (*a == 0)
	{
		*a = node;
		r->check_overlap = node;
		return ;
	}
	while (bottom->next != 0)
		bottom = bottom->next;
	bottom->next = node;
	r->check_overlap = node;
}

void	fill_stack(t_record *r, t_node **a_stack)
{
	int		i;
	int		j;
	char	**str;
	int		number;

	i = 1;
	j = 0;
	while (i <= r->argc)
	{
		str = ft_split(r->argv[i], ' ');
		if (str == 0)
			return ;
		j = 0;
		while (str[j])
		{
			number = integer_conversion(str[j], a_stack, str);
			add_node(r, a_stack, number);
			if (duplicate_check(r, a_stack, number) == 1)
				print_error(a_stack, 0, str);
			j++;
			r->count++;
		}
		i++;
		ft_split_free(str);
	}
}

int		is_it_sorted(t_node **a)
{
	int		before;
	t_node	*temp;

	temp = *a;
	before = temp->value;
	temp = temp->next;
	while (temp != 0)
	{
		if (before > temp->value)
			return (0);
		before = temp->value;
		temp = temp->next;
	}
	return (1);
}

void	free_stack(t_node **a)
{
	t_node *p;
	t_node *t;

	if (*a == 0)
		return ;
	p = *a;
	while (p != 0)
	{
		t = p->next;
		free(p);
		p = t;
	}
}

int		main(int argc, char **argv)
{
	t_node		*a_stack;
	t_node		*b_stack;
	t_record	r;

	a_stack = 0;
	b_stack = 0;
	if (argc > 1)
	{
		set_record(&r, argc, argv);
		fill_stack(&r, &a_stack);
		swap_sort(&r, &a_stack, &b_stack);
		free_stack(&a_stack);
	}
	return (0);
}
