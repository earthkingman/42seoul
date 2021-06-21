/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:57:25 by ji-park           #+#    #+#             */
/*   Updated: 2021/06/21 19:57:25 by ji-park          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node *top;
	t_node *second;
	t_node *bottom;

	top = *a;
	if (top != 0 && top->next != 0)
	{
		second = top->next;
		bottom = top->next;
		while (bottom->next != 0)
			bottom = bottom->next;
		bottom->next = top;
		top->next = 0;
		*a = second;
	}
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node *top;
	t_node *second;
	t_node *bottom;

	top = *b;
	if (top != 0 && top->next != 0)
	{
		second = top->next;
		bottom = top->next;
		while (bottom->next != 0)
			bottom = bottom->next;
		bottom->next = top;
		top->next = 0;
		*b = second;
	}
	write(1, "rb\n", 3);
}

void	rra(t_node **a)
{
	t_node *top;
	t_node *pre_bottom;
	t_node *bottom;

	top = *a;
	bottom = *a;
	while ((bottom->next)->next != 0)
		bottom = bottom->next;
	pre_bottom = bottom;
	bottom = bottom->next;
	bottom->next = top;
	pre_bottom->next = 0;
	*a = bottom;
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	t_node *top;
	t_node *pre_bottom;
	t_node *bottom;

	top = *b;
	bottom = *b;
	while ((bottom->next)->next != 0)
		bottom = bottom->next;
	pre_bottom = bottom;
	bottom = bottom->next;
	bottom->next = top;
	pre_bottom->next = 0;
	*b = bottom;
	write(1, "rrb\n", 4);
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
