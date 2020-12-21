#include "ft_printf.h"

void    ft_output_u(t_format *t_node)
{
    unsigned long int u;
    
    u = (unsigned long int)va_arg(t_node->ap, void *);
    do_str2(u, t_node);
    judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    ft_bzero(t_node->result,t_node->max_size);
    t_node->result[t_node->max_size] = 0;
    if (t_node->flag[0] == 1)
        p_flag_minus(t_node, t_node->num);
    else
        p_noflag(t_node, t_node->num); 
}
