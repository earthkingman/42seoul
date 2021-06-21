/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:56:27 by ji-park           #+#    #+#             */
/*   Updated: 2021/06/21 20:21:40 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_record *r, t_node **a)
{
	int		before;
	t_node	*p;

	p = *a;
	before = p->value;
	p = p->next;
	if ((before == r->min && p->value == r->max) ||
			(before == r->max && p->value != r->min) ||
			(before != r->max && p->value == r->min))
		sa(a);
	p = *a;
	before = p->value;
	p = p->next;
	if (before == r->max && p->value == r->min)
		ra(a);
	else if (before != r->min && p->value == r->max)
		rra(a);
}

void	sort_five2(t_node **a)
{
	t_node *top;
	t_node *second;
	t_node *bottom;

	top = *a;
	second = top->next;
	bottom = top->next;
	while (bottom->next != 0)
		bottom = bottom->next;
	if (top->value > bottom->value && bottom->value > second->value)
		ra(a);
	else if (bottom->value > top->value && top->value > second->value)
		sa(a);
	else if (second->value > top->value && top->value > bottom->value)
		sa(a);
	else if (top->value > second->value && second->value > bottom->value)
	{
		ra(a);
		sa(a);
	}
	else
	{
		rra(a);
		sa(a);
	}
}

void	sort_five(t_record *r, t_node **a, t_node **b)
{
	t_node *p;

	r->pa_num = 0;
	while (1)
	{
		p = *a;
		if (p->value == r->max && (is_it_sorted(&p->next)) == 1)
			ra(a);
		else if (*b != 0 && (is_it_sorted(a)) == 1)
		{
			pa(a, b);
			r->pa_num--;
		}
		else if (p->value == r->min || p->value == r->max)
		{
			pb(a, b);
			r->pa_num++;
		}
		else if (r->pa_num < 2)
			ra(a);
		else
			sort_five2(a);
		if (*b == 0 && (is_it_sorted(a)) == 1)
			return ;
	}
}

void	sort_many(t_record *r, t_node **a, t_node **b)
{
	r->a_now_num = r->count;
	if (is_it_sorted(a) == 1)
		return ;
	if ((is_descending(r, a)) == 1 && (arrange_descending(r, a, b)) == 1)
		return ;
	while (r->a_now_num != 0)
	{
		divide_move_a(r, a, b);
		if (r->pa_num != 0)
			divide_move_b(r, a, b);
	}
}

void	swap_sort(t_record *r, t_node **a, t_node **b)
{
	t_node *temp;

	temp = *b;
	if (r->count == 1 || (is_it_sorted(a)) == 1)
		return ;
	else if (r->count == 2)
	{
		if ((*a)->value == r->min)
			return ;
		else
			sa(a);
	}
	else if (r->count == 3)
		sort_three(r, a);
	else if (r->count == 5)
		sort_five(r, a, b);
	else
		sort_many(r, a, b);
}
