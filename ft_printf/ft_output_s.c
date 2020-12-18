#include "ft_printf.h"


void    check_null(t_format *t_node, char **str)
{
      t_node->size = 6;
      *str = "(null)";
}

void    ft_output_s(t_format *t_node)
{
    char *str;

    str = va_arg(t_node->ap, char *);
    t_node->size = ft_strlen(str);
    if (t_node->size == 0)
            check_null(t_node, &str);
    judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    ft_bzero(t_node->result,t_node->max_size);
    t_node->result[t_node->max_size] = 0;
    if (t_node->flag[0] == 1)
    {
        s_flag_minus(t_node, str);
    }
    else if (t_node->flag[1] == 1)
    {
        s_flag_zero(t_node, str);
    }
    else
    {
       s_noflag(t_node, str);
    } 
}