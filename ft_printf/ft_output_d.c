#include "ft_printf.h"


void    ft_output_d(t_format *t_node)
{
    int num;
    
    num = va_arg(t_node->ap, int);
    if (num >= 0)
        positive_d(t_node, num);
    else
        negative_d(t_node, num);
}


void    positive_d(t_format *t_node, int num)
{
    d_to_str(t_node, num);
    judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    ft_bzero(t_node->result,t_node->max_size + 1);
    if (t_node->flag[0] == 1)
        flag_minus(t_node, t_node->num);
    else if (t_node->flag[1] == 1)
        flag_zero(t_node, t_node->num);
    else
        noflag(t_node, t_node->num);
}


void    negative_d(t_format *t_node, int num)
{
    d_to_str(t_node, num);
    n_judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    ft_bzero(t_node->result,t_node->max_size + 1);
    if (t_node->flag[0] == 1)
        flag_minus(t_node, t_node->num);
    else if (t_node->flag[1] == 1)
        n_flag_zero(t_node, t_node->num);
    else
        noflag(t_node, t_node->num);
}