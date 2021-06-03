#include "push_swap.h"

void sa(t_list **a)
{
    t_list *p;
    t_list *top;
    t_list *second;

    top = *a;
    second = (*a)->next;
    top->next = second->next;
    *a = second;
    second->next = top;
    write(1, "sa\n", 3);
}

void sb(t_list **b)
{
    t_list *p;
    t_list *top;
    t_list *second;

    top = *b;
    second = (*b)->next;
    top->next = second->next;
    *b = second;
    second->next = top;
    write(1, "sb\n", 3);
}

void pa(t_list **a, t_list **b)
{
    t_list *top_a;

    top_a = *a;
    *a = top_a->next;
    top_a->next = *b;
    *b = top_a;
    write(1, "pa\n", 3);
}

void pb(t_list **a, t_list **b)
{
    t_list *top_b;

    top_b = *b;
    *b = top_b->next;
    top_b->next = *a;
    *a = top_b;
    write(1, "pb\n", 3);
}