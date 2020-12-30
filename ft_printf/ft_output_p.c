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

void    ft_output_p(t_format *t_node)
{
    unsigned long int p;
    
    p = (unsigned long int)va_arg(t_node->ap, void *);
    h_to_str(p, t_node);
    exception_null(t_node, p);
    judge_max(t_node);
    if ((t_node->result = (char *)malloc(sizeof(char) * (t_node->max_size + 3))) == 0)
        return ;
    pf_bzero(t_node->result,t_node->max_size + 3);
    if (t_node->flag[0] == 1)
        p_flag_minus(t_node, t_node->num);
    else
        p_noflag(t_node, t_node->num); 
}



