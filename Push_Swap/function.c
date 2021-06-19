#include "push_swap.h"

void sa(t_node **a)
{
	t_node *p; 
	t_node *top;
	t_node *second;

	second = *a;
	if (second->next != 0) //다음 가리키는 노드가 있을 경우
	{
		top = second->next; // 현재 가리키는 노드의 다음 노드를 탑에 넣음
		p = top->next; // 
		*a = top; //
		top->next = second;
		second->next = p;
	}
	write(1, "sa\n", 3);
}

void sb(t_node **b)
{
	t_node *p;
	t_node *top;
	t_node *second;

	second = *b;
	if (second != 0 && second->next != 0)
	{
		top = second->next;
		p = top->next;
		*b = top;
		top->next = second;
		second->next = p;
	}
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