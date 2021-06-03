#include "push_swap.h"

long integer_Conversion(char *argv)
{
    int minus;
    int i;
    long number;

    i = 0;
    number = 0;
    if (argv[i] == '+')
        minus = 1;
    else if (argv[i] == '-')
        minus = -1;
    if (!(argv[i] >= '0' && argv[i] <= '9'))
        return -1;
    while (argv[i] != 0)
    {
        if (argv[i] >= '0' && argv[i] <= '9')
            number = (number * 10) + (argv[i] - '0');
        i++;
    }
    number = number * minus;
    if (number < 0 || number > 2147483648)
        return -1;
    return number;
}

int duplicateCheck(t_list **a, int value)
{
    t_list *temp;

    temp = *a;
    while (temp->next != 0)
    {
        if (value == temp->value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void add_Node(t_record *r, t_list **a, int value)
{
    t_list *node;
    t_list *bottom;

    if (r->max < value)
        r->max = value;
    if (r->min > value)
        r->min = value;
    node = (t_list *)malloc(sizeof(t_list));
    node->value = value;
    node->next = 0;
    bottom = *a;
    if (*a == 0)
    {
        *a = node;
        return;
    }
    while (bottom->next != 0)
        bottom = bottom->next;
    bottom->next = node;
}

void fill_stack(t_record *r, t_list **a_stack)
{
    int i;
    int j;
    char **str;
    int number;
    t_list *temp;

    i = 0;
    j = 0;
    temp = 0;
    while (i < r->argc)
    {
        str = ft_split(r->argv[i], ' ');
        if (str == 0)
            return NULL;
        while (str[j])
        {
            number = integer_Conversion(str[j]);
            if (duplicateCheck(a_stack, number) == 1)
                return NULL;
            add_Node(r, a_stack, number);
            j++;
        }
        //split free 함수 들어가야함
        i++;
    }
    r->count = j;
}

void set_record(t_record *r, int argc, char **argv)
{
    r->argc = argc;
    r->argv = argv;
    r->max = -2147000000;
    r->min = 2147000000;
    r->pa_num = 0;
    r->rra_num = 0;
    r->rrb_num = 0;
    r->a_now_num = 0;
    r->b_now_num = 0;
}

void print_error(t_list **a, t_list **b, char **s)
{
    int i;

    if (a != 0)
        free_stack(a);
    if (b != 0)
        free_stack(b);
    if (s != 0)
    {
        i = -1;
        while (s[++i] != 0)
            free(s[i]);
        free(s[i]);
        free(s);
    }
    write(2, "Error\n", 6);
    exit(0);
}

int isItSorted(t_list **a)
{
    int before;
    t_list *temp;

    temp = *a;
    before = temp->value;
    temp = temp->next;
      
    while (temp->next != 0)
    {
        if (before > temp->value)
            return 0;
        before = temp->value;
        temp = temp->next;
    }
    return 1;
}

void sort_three(t_record *r, t_list **a)
{
    int		before;
	t_list *p;

	p = *a;
	before = p->value;
	p = p->next;
	if ((before == r->min && p->value == r->max) ||
	(before == r->max && p->value != r->min) ||
	(before != r->max && p->value == r->min))
		sa(a, 0, 0);
	p = *a;
	before = p->value;
	p = p->next;
	if (before == r->max && p->value == r->min)
		ra(a, 0, 0);
	else if (before != r->min && p->value == r->max)
		rra(a, 0, 0);
}

void sort_many(t_record *r, t_list **a, t_list **b)
{
    r->a_now_num = r->argc;
    if ((isItSorted))
}

void swap_sort(t_record *r, t_list **a, t_list **b)
{
    if (r->count == 1 || (isItSorted(a)) == 1)
        return ;
    else if (r->count == 2)
    {
        if ((*a)->value == r->min)
            return;
        else
            sa(a);
    }
    else if (r->count == 3)
        sort_three(r, a);
    else
        sort_many(r, a, b);
}

int main(int argc, char **argv)
{
    t_list *a_stack;
    t_list *b_stack;
    t_record r;

    a_stack = 0;
    b_stack = 0;
    if (argc > 2)
    {
        set_record(&r, argc, argv);
        fill_stack(&r, &a_stack);
        swap_sort(&r, &a_stack, &b_stack);
    }
    return 0;
}