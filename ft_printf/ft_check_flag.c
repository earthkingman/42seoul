#include "ft_printf.h"

void	check_percent(t_format *t_node)
{
	while (*t_node->str != 0)
    {
        if (*t_node->str == '%')
		{
			t_node->str++;
			check_flag(t_node);
        	check_wid(t_node);
        	check_prec(t_node);
			check_spec(t_node);
			check_spec2(t_node);
			ft_putstr(t_node);
			//show_node(t_node);
			init_node(t_node);
		}
        else
        {
            ft_putchar(*t_node->str);
            t_node->str++;
        }
    }
}

void	check_spec2(t_format *t_node)
{
	if (t_node->spec == 'c')
		ft_output_c(t_node);
	else if (t_node->spec == 's')
		ft_output_s(t_node);
	else if (t_node->spec == 'd')
		ft_output_d(t_node);
	else if(t_node->spec == 'i')
		ft_output_d(t_node);
	else if(t_node->spec == 'c')
		ft_output_c(t_node);
	else if(t_node->spec == 'p')
		ft_output_p(t_node);
	// else if(t_node->spec == 'c')
	// 	ft_output_c(t_node);
	// else if(t_node->spec == 'c')
	// 	ft_output_c(t_node);
}

void	check_spec(t_format *t_node)
{
	if (*t_node->str == 'c')
		t_node->spec = 'c';	
	else if (*t_node->str == 's')
		t_node->spec = 's';
	else if (*t_node->str == 'd')
		t_node->spec = 'd';
	else if (*t_node->str == 'p')
		t_node->spec = 'p';	
	else if (*t_node->str == 'i')
		t_node->spec = 'i';
	else if (*t_node->str == 'u')
		t_node->spec = 'u';	
	else if (*t_node->str == 'x')
		t_node->spec = 'x';
	else if (*t_node->str == 'X')
		t_node->spec = 'X';
	t_node->str++;
}

int		check_star(t_format *t_node)
{
	int num;

	num = 0;
	if (*t_node->str == '*')
	{
		t_node->flag[3] = 1;
		num = va_arg(t_node->ap, int); 
		t_node->str++;
	}
	return (num);
}

void	check_flag(t_format *t_node)
{
	while (1)
	{
		if (*t_node->str == '-')
			t_node->flag[0] = 1;
		else if (*t_node->str == '0')
			t_node->flag[1] = 1;
		else
			return ;
		t_node->str++;
	}
}

void	check_wid(t_format *t_node)
{
	int i;
	int sign;
	int answer;
	t_node->wid = check_star(t_node);
	if (t_node->wid > 0)
		return ;
	answer = 0;
	while (*t_node->str >= '0' && *t_node->str <= '9')
	{
		answer = answer * 10 + (*t_node->str - 48);
		t_node->str++;
	}
	t_node->wid = answer;
}

void	check_prec(t_format *t_node)
{
	int answer;

	answer = 0;
	if (*t_node->str == '.')
	{
		t_node->flag[2] = 1;
		t_node->str++;
		t_node->prec = check_star(t_node);
		if (t_node->prec > 0)
			return ;	
		while (*t_node->str >= '0' && *t_node->str <= '9')
		{
			answer = answer * 10 + (*t_node->str - 48);
			t_node->str++;
		}
		t_node->prec = answer;
	}
	else
		return ;
}