#include "push_swap.h"

long integer_Conversion(char *argv, t_node **a, char **s)
{
    int minus;
    int i;
    long number;

    minus = 1;
    i = 0;
    number = 0;
    if (argv[i] == '+')
        i++;
    else if (argv[i] == '-')
    {
        minus = -1;
        i++;
    }
    if (!(argv[i] >= '0' && argv[i] <= '9'))
        print_error(a, 0, s);
    while (argv[i] != 0)
    {
        if (argv[i] >= '0' && argv[i] <= '9')
            number = (number * 10) + (argv[i] - '0');
        i++;
    }
    number = number * minus;
    if (number < -2147483648 || number > 2147483648)
        print_error(a, 0, s);
    return number;
}

int duplicateCheck(t_record *r, t_node **a, int value)
{
    t_node *temp;

    temp = *a;
    while (temp != r->check_overlap)
    {
        if (value == temp->value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void add_Node(t_record *r, t_node **a, int value)
{
    t_node *node;
    t_node *bottom;

    if (r->max < value)
        r->max = value;
    if (r->min > value)
        r->min = value;
    node = (t_node *)malloc(sizeof(t_node));
    node->value = value;
    node->next = 0;
    bottom = *a;
    if (*a == 0)
    {
        *a = node;
        r->check_overlap = node;
        return;
    }
    while (bottom->next != 0)
        bottom = bottom->next;
    bottom->next = node;
    r->check_overlap = node;
}

void fill_stack(t_record *r, t_node **a_stack)
{
    int i;
    int j;
    char **str;
    int number;
    t_node *temp;

    i = 1;
    j = 0;
    temp = 0;
    while (i <= r->argc)
    {
        str = ft_split(r->argv[i], ' ');
        if (str == 0)
            return;
        j = 0;
        while (str[j])
        {
            number = integer_Conversion(str[j], a_stack, str);
            add_Node(r, a_stack, number);
            if (duplicateCheck(r, a_stack, number) == 1)
                print_error(a_stack, 0, str);
            j++;
            r->count++;
        }

        i++;
        ft_split_free(str);
    }
}

void ft_split_free(char **s)
{
    int i;

    i = -1;
    while (s[++i] != 0)
        free(s[i]);
    free(s[i]);
    free(s);
}

void set_record(t_record *r, int argc, char **argv)
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

void print_error(t_node **a, t_node **b, char **s)
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

int isItSorted(t_node **a)
{
    int before;
    t_node *temp;

    temp = *a;
    before = temp->value;
    temp = temp->next;

    while (temp != 0)
    {
        if (before > temp->value)
            return 0;
        before = temp->value;
        temp = temp->next;
    }
    return 1;
}

void sort_three(t_record *r, t_node **a)
{
    int before;
    t_node *p;

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

void sort_five(t_record *r, t_node **a, t_node **b)
{
    t_node *p;

	r->pa_num = 0;
	while (1)
	{
		p = *a;
		if (p->value == r->max && (isItSorted(&p->next)) == 1)
			ra(a);
		else if (*b != 0 && (isItSorted(a)) == 1)
		{
			pa(a, b);
			r->pa_num--;
		}
		else if (p->value == r->min || p->value == r->max)
		{
			pb(a, b);
			r->pa_num++;
		}
		else if (r->pa_num < 2) // 최댓값이랑 최솟값이 빠지기 전까지
			ra(a);
		else
			sort_five2(a);
		if (*b == 0 && (isItSorted(a)) == 1)
			return ;
	}
}

void swap_sort(t_record *r, t_node **a, t_node **b)
{
    t_node *temp;

    temp = *b;
    if (r->count == 1 || (isItSorted(a)) == 1)
        return;
    else if (r->count == 2)
    {
        if ((*a)->value == r->min)
            return;
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

int get_mid_value(t_node **node, int len)
{
    t_node *temp;
    int max;
    int min;

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

void moveA(t_record *r, t_node **a, t_node **b, int mid)
{
    t_node *temp;

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

void moveB(t_record *r, t_node **a, t_node **b, int mid)
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

void recordA(t_record *r)
{
    t_node *t;

    t = (t_node *)malloc(sizeof(t_node) * 1);
    t->value = r->rra_num;
    t->next = r->a_info;
    r->a_info = t;
}

void recordB(t_record *r)
{
    t_node *t;

    t = (t_node *)malloc(sizeof(t_node) * 1);
    t->value = r->rrb_num;
    t->next = r->b_info;
    r->b_info = t;
}

void sort_fixA(t_record *r, t_node **a)
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
        return;
    }
    p = *a;
    if (p->value > (p->next)->value)
        sa(a);
    ra(a);
    ra(a);
    r->a_now_num = 0;
}

void sort_fixB(t_record *r, t_node **a, t_node **b)
{
    t_node *p;

    r->pa_num -= r->b_now_num;       //b스택에 남아있는 갯수 -> pa를 해야하는횟수
    r->a_now_num = r->a_info->value; //rra 해야하는 횟수
    p = r->a_info;
    r->a_info = r->a_info->next;
    free(p);
    if (r->b_now_num == 1)
    {
        pa(a, b);
        ra(a);
        r->b_now_num = 0;
        return;
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

void divide_moveA(t_record *r, t_node **a, t_node **b)
{
    int mid;
    t_node *p;

    mid = 0;
    if (r->a_now_num < 3)
    {
        sort_fixA(r, a);
        return;
    }
    if (r->a_now_num == r->argc)
        mid = (r->max + r->min) / 2;
    else
        mid = get_mid_value(a, r->a_now_num);
    moveA(r, a, b, mid);
    recordA(r);
    p = *a;
    while (r->rra_num > 0 && (r->a_info->next != 0 || p->value == r->min))
    {
        rra(a);
        r->rra_num--;
    }
    r->rra_num = 0;
}

void divide_moveB(t_record *r, t_node **a, t_node **b)
{
    int mid;

    mid = 0;
    if (r->b_now_num < 3)
    {
        sort_fixB(r, a, b);
        return;
    }
    mid = get_mid_value(b, r->b_now_num);
    moveB(r, a, b, mid);
    recordB(r);
    while (r->rrb_num > 0 && (r->b_info->next != 0))
    {
        rrb(b);
        r->rrb_num--;
    }
    r->rrb_num = 0;
}

int arrange_descending(t_record *r, t_node **a, t_node **b) //탑에서 오름차순으로 변경
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

int is_descending(t_record *r, t_node **a) //탑에서 내림차순으로 되어있는지 확인
{
    int before;
    t_node *p;

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

void sort_many(t_record *r, t_node **a, t_node **b)
{
    r->a_now_num = r->count;
    if (isItSorted(a) == 1)
        return;
    if ((is_descending(r, a)) == 1 && (arrange_descending(r, a, b)) == 1)
        return;
    while (r->a_now_num != 0)
    {
        divide_moveA(r, a, b);
        if (r->pa_num == 0)
            continue ;
            divide_moveB(r, a, b);
    }
}

void free_stack(t_node **a)
{
    t_node *p;
    t_node *t;

    if (*a == 0)
        return;
    p = *a;
    while (p != 0)
    {
        t = p->next;
        free(p);
        p = t;
    }
}

int main(int argc, char **argv)
{
    t_node *a_stack;
    t_node *b_stack;
    t_record r;

    a_stack = 0;
    b_stack = 0;
    if (argc > 1)
    {
        set_record(&r, argc, argv);
        fill_stack(&r, &a_stack);
        swap_sort(&r, &a_stack, &b_stack);
        free_stack(&a_stack);
    }
    return 0;
}