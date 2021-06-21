/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:56:43 by ji-park           #+#    #+#             */
/*   Updated: 2021/06/21 20:20:18 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_record(t_record *r, int argc, char **argv)
{
	r->argc = argc;
	r->argv = argv;
	r->max = -2147483648;
	r->min = 2147483647;
	r->pa_num = 0;
	r->rra_num = 0;
	r->rrb_num = 0;
	r->a_now_num = 0;
	r->b_now_num = 0;
}

int		get_mid_value(t_node **node, int len)
{
	t_node	*temp;
	int		max;
	int		min;

	temp = *node;
	max = temp->value;
	min = temp->value;
	while (len > 0)
	{
		if (temp->value > max)
			max = temp->value;
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
		len--;
	}
	return (max + min) / 2;
}

int		arrange_descending(t_record *r, t_node **a, t_node **b)
{
	int i;

	i = r->count;
	pb(a, b);
	while (--i > 0)
	{
		pb(a, b);
		rb(b);
	}
	i = r->argc;
	while (i-- > 0)
		pa(a, b);
	return (1);
}

int		is_descending(t_record *r, t_node **a)
{
	int		before;
	t_node	*p;

	p = *a;
	if (p->value != r->max)
		return (0);
	before = p->value;
	p = p->next;
	while (p != 0)
	{
		if (before < p->value)
			return (0);
		before = p->value;
		p = p->next;
	}
	return (1);
}
