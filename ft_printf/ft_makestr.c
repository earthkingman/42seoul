#include "ft_printf.h"


void    noflag(t_format *t_node, char *str)
{
    int i;
    int j;
    int size;

    i = 0;
    j = 0;
    if (str != NULL)
    {
        size = t_node->size;
        if (t_node->size < t_node->prec)
            size = t_node->prec;
        while (t_node->wid > size + i)
            t_node->result[i++] = ' ';
        while (t_node->size + j < t_node->prec)
        {
            t_node->result[i++] = '0';
            j++;
        }
        while (*str != 0)
            t_node->result[i++] = *str++;
    }
}

void    flag_minus(t_format *t_node, char *str)
{
    int i;

    i = 0;
    if (str != NULL)
    {
        while (t_node->prec > t_node->size + i)
            t_node->result[i++] = '0';       
        while (*str != 0)
            t_node->result[i++] = *str++;
        while (i < t_node->max_size)
            t_node->result[i++] = ' ';
    }
}

void    flag_zero(t_format *t_node, char *str)
{
    int     i;
    int     j;
    
    i = 0;
    j = t_node->max_size - t_node->size;
    if (t_node->flag[2] == 1)
    {
        if (t_node->prec > t_node->size)
           j = t_node->max_size - t_node->prec;
    }
    if (str != NULL)
    {
        while (j-- > 0)
            t_node->result[i++] = ' ';
        j = t_node->prec - t_node->size;
        while (j-- > 0)
            t_node->result[i++] = '0';
        while (*str != 0)
             t_node->result[i++] = *str++;
    }
}

void    s_noflag(t_format *t_node, char *str)
{
    int i;
    int prec;
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
                while (str[i] != 0 && i < t_node->prec)
                {
                    t_node->result[i] = str[i];
                    i++; 
                }
        }
        else
        {
            while (str[i] != 0)
            {
                t_node->result[i] = str[i];
                i++;
            }
        }
    }    
    while (i < t_node->wid)
    {
        t_node->result[i] = ' ';
        i++;
    }
}

void    s_flag_zero(t_format *t_node, char *str)
{
    int i;
    int prec;
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