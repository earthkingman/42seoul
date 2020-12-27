#include "ft_printf.h"

void    p_flag_minus(t_format *t_node, char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (str != NULL)
    {
        while (*str != 0)
            t_node->result[i++] = *str++;
        while (t_node->wid > t_node->size + j)
        {
            t_node->result[i++] = ' ';
            j++;
        } 
    }
}

void    p_noflag(t_format *t_node, char *str)
{
    int i;

    i = 0;
    if (str != NULL)
    {
        while (t_node->wid > t_node->size + i)
            t_node->result[i++] = ' ';       
        while (*str != 0)
            t_node->result[i++] = *str++;
    }
}

void    ft_output_p(t_format *t_node)
{
    unsigned long int p;
    
    p = (unsigned long int)va_arg(t_node->ap, void *);
    h_to_str(p, t_node);
    judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 1))) == 0)
        return ;
    ft_bzero(t_node->result,t_node->max_size + 1);
    if (t_node->flag[0] == 1)
        p_flag_minus(t_node, t_node->num);
    else
        p_noflag(t_node, t_node->num); 
}



