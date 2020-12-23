#include "ft_printf.h"

void    ft_output_c(t_format *t_node)
{   
    char str[2];
    unsigned char c;

    c = (unsigned char)va_arg(t_node->ap, int);
    str[0] = c;
    str[1] = 0;
    t_node->size = 1;
    judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    ft_bzero(t_node->result,t_node->max_size + 1);
    if (t_node->flag[0] == 1)
        s_flag_minus(t_node, str);
    else if (t_node->flag[1] == 1)
        s_flag_zero(t_node, str);
    else
       s_noflag(t_node, str);
}
