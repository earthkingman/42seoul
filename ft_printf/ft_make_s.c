#include "ft_printf.h"

void    s_noflag(t_format *t_node, char *str)
{
    int i;
    int size;

    i = 0;
    size = t_node->size;
    if (t_node->flag[2] == 1)
        {
            if (t_node->prec < t_node->size)
                size = t_node->prec;
        }
    if (str != NULL)
    { 
            while (size + i  < t_node->wid)
            {
                t_node->result[i++] = ' ';
            }
            while (*str != 0 && size > 0)
            {
                t_node->result[i++] = *str++;
                size--;
            }
    }
}

void    s_flag_minus(t_format *t_node, char *str)
{
    int i;

    i = 0;
    if (str != NULL)
    {
        if (t_node->flag[2] == 1)
        {
            while (*str != 0 && i < t_node->prec)
                t_node->result[i++] = *str++; 
        }
        else
        {
            while (*str != 0)
                t_node->result[i++] = *str++;
        }
    }    
    while (i < t_node->wid)
        t_node->result[i++] = ' ';
}

void    s_flag_zero(t_format *t_node, char *str)
{
    int i;
    int size;

    i = 0;
    size = t_node->size;
    if (t_node->flag[2] == 1)
        {
            if (t_node->prec < t_node->size)
                size = t_node->prec;
        }
    if (str != NULL)
    { 
            while (size + i  < t_node->wid)
            {
                t_node->result[i++] = '0';
            }
            while (*str != 0 && size > 0)
            {
                t_node->result[i++] = *str++;
                size--;
            }
    }
}
