/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:56:37 by ji-park           #+#    #+#             */
/*   Updated: 2021/06/21 20:22:10 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b(t_record *r, t_node **a, t_node **b, int mid)
{
	t_node *temp;

	while (r->b_now_num > 0)
	{
		temp = *b;
		if (temp->value <= mid)
		{
			pa(a, b);
			r->pa_num--;
			r->a_now_num++;
		}
		else
		{
			rb(b);
			r->rrb_num++;
		}
		r->b_now_num--;
	}
}

void	record_b(t_record *r)
{
	t_node *t;

	t = (t_node *)malloc(sizeof(t_node) * 1);
	t->value = r->rrb_num;
	t->next = r->b_info;
	r->b_info = t;
}

void	sort_fix_b(t_record *r, t_node **a, t_node **b)
{
	t_node *p;

	r->pa_num -= r->b_now_num;
	r->a_now_num = r->a_info->value;
	p = r->a_info;
	r->a_info = r->a_info->next;
	free(p);
	if (r->b_now_num == 1)
	{
		pa(a, b);
		ra(a);
		r->b_now_num = 0;
		return ;
	}
	p = *b;
	if (p->value > (p->next)->value)
		sb(b);
	pa(a, b);
	ra(a);
	pa(a, b);
	ra(a);
	r->b_now_num = 0;
}

void	divide_move_b(t_record *r, t_node **a, t_node **b)
{
	int		mid;

	mid = 0;
	if (r->b_now_num < 3)
	{
		sort_fix_b(r, a, b);
		return ;
	}
	mid = get_mid_value(b, r->b_now_num);
	move_b(r, a, b, mid);
	record_b(r);
	while (r->rrb_num > 0 && (r->b_info->next != 0))
	{
		rrb(b);
		r->rrb_num--;
	}
	r->rrb_num = 0;
}
