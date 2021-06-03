#include "push_swap.h"

void ra(t_list **a)
{
    t_list *top;
    t_list *bottom;

    top = *a;
    *a = (*a)->next;
    bottom = *a;
    while (bottom->next != 0)
        bottom = bottom->next;
    bottom->next = top;
    top->next = 0;
    write(1, "ra\n", 3);
}

void rb(t_list **b)
{
    t_list *top;
    t_list *bottom;

    top = *b;
    *b = (*b)->next;
    bottom = *b;
    while (bottom->next != 0)
        bottom = bottom->next;
    bottom->next = top;
    top->next = 0;
    write(1, "ra\n", 3);
}

void rra(t_list **a)
{
    t_list *top;
    t_list *pre_bottom;
    t_list *bottom;

    top = *a;
    bottom = *a;
    while ((bottom->next)->next != 0)
        bottom = bottom->next;
    pre_bottom = bottom;
    bottom = bottom->next;
    bottom->next = top;
    pre_bottom->next = 0;
    *a = bottom;
    write(1, "rra\n", 3);
}

void rrb(t_list **b)
{
    t_list *top;
    t_list *pre_bottom;
    t_list *bottom;

    top = *b;
    bottom = *b;
    while ((bottom->next)->next != 0)
        bottom = bottom->next;
    pre_bottom = bottom;
    bottom = bottom->next;
    bottom->next = top;
    pre_bottom->next = 0;
    *b = bottom;
    write(1, "rrb\n", 3);
}

void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}