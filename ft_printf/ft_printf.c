#include "ft_printf.h"

int	pf_strlen(char *str)
{
	int i;

    if (str == NULL)
        return(0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	pf_bzero(void *ptr, size_t size)
{
	int				i;
	unsigned char	*startptr;

	startptr = (unsigned char *)ptr;
	i = 0;
	while (size--)
	{
		startptr[i] = 0;
		i++;
	}
}

void    judge_max(t_format *t_node)
{
    if (t_node->prec > t_node->wid)
    {
        if (t_node->prec > t_node->size)
            t_node->max_size = t_node->prec;
        else
            t_node->max_size =  t_node->size;
    }
    else
    {
        if (t_node->wid > t_node-> size)
            t_node->max_size = t_node->wid;
        else
            t_node->max_size = t_node-> size;
    }
}


void    n_judge_max(t_format *t_node)
{
    if (t_node->prec > t_node->wid)
    {
        if (t_node->prec > t_node->size)
            t_node->max_size = t_node->prec + 1;
        else
            t_node->max_size =  t_node->size;
    }
    else
    {
        if (t_node->wid > t_node-> size)
            t_node->max_size = t_node->wid;
        else
            t_node->max_size = t_node-> size;
    }
}

void	do_itoa(unsigned int tmp, t_format *t_node, int len)
{
	while (tmp > 0)
	{
		t_node->num[len--] = (tmp % 10) + 48;
		tmp = tmp / 10;
	}
}

long long	check_size(long long n)
{
	long long			i;

	i = 0;
	if (n < 0)
		n = n * -1;
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(t_format *t_node)
{
    int i;

    i = 0;
    if (t_node->spec == 'c' && t_node->num[0] == '\0')
    {
       write(1, &t_node->result, t_node->max_size); 
       return ;
    }
    while(t_node->result[i] != 0)
    {
        write(1, &t_node->result[i], 1);
        i++;
    }
}

int ft_printf(const char *format, ...)
{
	int size;

    t_format *t_node;
    t_node = (t_format*)malloc(sizeof(t_format));
    va_start(t_node->ap,format);
    init_firstnode(t_node,(char *)format);
    start_printf(t_node);
    if (t_node->spec == '0')
    {
        va_end(t_node->ap);
        free(t_node);
        return -1;
    }
    va_end(t_node->ap);
	size = t_node->nums;
    free(t_node);
	return(size);
}
