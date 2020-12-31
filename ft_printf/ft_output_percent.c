#include "ft_printf.h"

void    ft_output_percent(t_format *t_node)
{   
    t_node->num[0] = '%';
    t_node->size = 1;
    judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    pf_bzero(t_node->result,t_node->max_size + 1);
    if (t_node->flag[0] == 1)
    {
        s_flag_minus(t_node, t_node->num);
    }
    else if (t_node->flag[1] == 1)
    {
        s_flag_zero(t_node, t_node->num);
    }
    else
    {
       s_noflag(t_node, t_node->num);
    }
}
