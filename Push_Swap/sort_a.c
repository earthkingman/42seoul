/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortA.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:56:40 by ji-park           #+#    #+#             */
/*   Updated: 2021/06/21 20:17:13 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a(t_record *r, t_node **a, t_node **b, int mid)
{
	t_node	*temp;

	while (r->a_now_num > 0)
	{
		temp = *a;
		if (mid >= (*a)->value)
		{
			pb(a, b);
			r->pa_num++;
			r->b_now_num++;
		}
		else
		{
			ra(a);
			r->rra_num++;
		}
		r->a_now_num--;
	}
}

void	sort_fix_a(t_record *r, t_node **a)
{
	t_node *p;

	p = r->b_info;
	if (p != 0)
	{
		r->b_now_num = r->b_info->value;
		r->b_info = r->b_info->next;
	}
	free(p);
	if (r->a_now_num == 1)
	{
		ra(a);
		r->a_now_num = 0;
		return ;
	}
	p = *a;
	if (p->value > (p->next)->value)
		sa(a);
	ra(a);
	ra(a);
	r->a_now_num = 0;
}

void	divide_move_a(t_record *r, t_node **a, t_node **b)
{
	int		mid;
	t_node	*p;

	mid = 0;
	if (r->a_now_num < 3)
	{
		sort_fix_a(r, a);
		return ;
	}
	if (r->a_now_num == r->argc)
		mid = (r->max + r->min) / 2;
	else
		mid = get_mid_value(a, r->a_now_num);
	move_a(r, a, b, mid);
	record_a(r);
	p = *a;
	while (r->rra_num > 0 && (r->a_info->next != 0 || p->value == r->min))
	{
		rra(a);
		r->rra_num--;
	}
	r->rra_num = 0;
}

void	record_a(t_record *r)
{
	t_node	*t;

	t = (t_node *)malloc(sizeof(t_node) * 1);
	t->value = r->rra_num;
	t->next = r->a_info;
	r->a_info = t;
}
