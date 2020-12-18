#include "ft_printf.h"

void    ft_output_c(t_format *t_node)
{
    char *c;
    c = va_arg(t_node->ap, char *);
    t_node->size = 1;
    judge_max(t_node); 
}
