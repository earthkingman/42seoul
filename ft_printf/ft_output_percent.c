#include "ft_printf.h"

void    ft_output_percent(t_format *t_node)
{   
    t_node->max_size = 1;
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    pf_bzero(t_node->result,t_node->max_size + 1);
    t_node->result[0] = '%';
}
