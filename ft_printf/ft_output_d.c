#include "ft_printf.h"

void    d_check_null(t_format *t_node)
{
    t_node->size = 1;
    t_node->num[0]= '0';
    t_node->num[1]= 0;
}

void    ft_output_d(t_format *t_node)
{
    int num;
    
    num = va_arg(t_node->ap, int);
    do_str(t_node, num);
    if (t_node->size == 0)
        d_check_null(t_node);
    judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    ft_bzero(t_node->result,t_node->max_size);
    t_node->result[t_node->max_size] = 0;
    if (t_node->flag[0] == 1)
        flag_minus(t_node, t_node->num);
    else if (t_node->flag[1] == 1)
        flag_zero(t_node, t_node->num);
    else
        noflag(t_node, t_node->num);
}
