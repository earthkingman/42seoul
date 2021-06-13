#include "push_swap.h"

void sa(t_node **a)
{
    t_node *top;
    t_node *second;

    top = *a;
    second = (*a)->next;
    top->next = second->next;
    *a = second;
    second->next = top;
    write(1, "sa\n", 3);
}

void sb(t_node **b)
{
    t_node *top;
    t_node *second;

    top = *b;
    second = (*b)->next;
    top->next = second->next;
    *b = second;
    second->next = top;
    write(1, "sb\n", 3);
}

void pa(t_node **a, t_node **b)
{
	t_node *b_top;
	t_node *a_second;

	if (*b != 0)
	{
		b_top = *b;
		*b = b_top->next != 0 ? b_top->next : 0;
		a_second = *a;
		*a = b_top;
		b_top->next = a_second;
	}
	write(1, "pa\n", 3);
}

void pb(t_node **a, t_node **b)
{

	t_node *a_top;
	t_node *b_second;

	a_top = *a;
	*a = a_top->next != 0 ? a_top->next : 0;
	b_second = *b;
	*b = a_top;
	a_top->next = b_second;
	write(1, "pb\n", 3);
}