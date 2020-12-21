#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>


typedef struct s_format
{
    char        *str;
    char        flag[4];
    char        spec;
    char        num[21];
    char        *result;
    va_list     ap;
    int         wid;
    int         prec;
    int         size;
    int         max_size;
    int         nums;
}               t_format;


void    init_zero(t_format *t_node);
void    d_check_null(t_format *t_node);
void    check_null(t_format *t_node, char **str);
void	ft_bspace(void *ptr, size_t size);
void	ft_bzero(void *ptr, size_t size);
void    p_flag_minus(t_format *t_node, char *str);
void    p_noflag(t_format *t_node, char *str);
void    s_noflag(t_format *t_node, char *str);
void    s_flag_zero(t_format *t_node, char *str);
void    s_flag_minus(t_format *t_node, char *str);
void    flag_zero(t_format *t_node, char *str);
void    flag_minus(t_format *t_node, char *str);
void    noflag(t_format *t_node, char *str);
int     ft_strlen(char *str);
void    judge_max(t_format *t_node);
void    ft_output_X(t_format *t_node);
void    ft_output_x(t_format *t_node);
void    ft_output_u(t_format *t_node);
void    ft_output_p(t_format *t_node);
void    ft_output_s(t_format *t_node);
void    ft_output_d(t_format *t_node);
void    ft_output_c(t_format *t_node);
void    select_spec(t_format *t_node);
long long	check_size(long long n);
void	do_itoa(unsigned int tmp, t_format *t_node, int len);
void	do_str(t_format *t_node, int n);
void    do_str2(long long addr, t_format *t_node);
void	check_spec(t_format *t_node);
void	check_spec2(t_format *t_node);
int	    check_star(t_format *t_node);
void	check_wid(t_format *t_node);
void	check_prec(t_format *t_node);
void	check_percent(t_format *t_node);
void    show_node(t_format *t_node);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void    ft_putstr(t_format *t_node);
void    init_firstnode(t_format *t_node, char *format);
void    init_node(t_format *t_node);
void	check_flag(t_format *t_node);

#endif