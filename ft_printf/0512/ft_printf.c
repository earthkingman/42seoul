#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int i;

    if (str == NULL)
        return(0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_bzero(void *ptr, size_t size)
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

void    judge_max(t_format *t_node) //너비 정확도 문자열 길이 중 긴거 리턴
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

void	d_to_str(t_format *t_node, int n)
{
	int			len;
	unsigned int	tmp;

	if (n == 0)
    {
        t_node->num[0] = '0';
        t_node->num[1] = 0;
        t_node->size = 1;
        return ;
    }
	len = check_size(n);
	if (n < 0)
	{
		tmp = n * -1;
		len++;
	}
	else
		tmp = n;
    t_node->size = len;
	t_node->num[len] = 0;
	len--;
	if (n < 0)
		t_node->num[0] = '-';
	do_itoa(tmp, t_node, len);
}


void	u_to_str(t_format *t_node, unsigned int n)
{
	int			len;
	unsigned int	tmp;

	if (n == 0)
    {
        t_node->num[0] = '0';
        t_node->num[1] = 0;
        t_node->size = 1;
        return ;
    }
	len = check_size(n);
	tmp = n;
    t_node->size = len;
	t_node->num[len] = 0;
	len--;
	do_itoa(tmp, t_node, len);
}



void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(t_format *t_node)
{
    int i;

    i = 0;
    while(t_node->result[i] != 0)
    {
        write(1, &t_node->result[i], 1);
        i++;
    }
}

void show_node(t_format *t_node)
{
    int i = 0;
    printf("\nstr : %s\n", t_node->str);
    printf("flag[0] -   : %d\n", t_node->flag[0]);
    printf("flag[1] 0   : %d\n", t_node->flag[1]);
    printf("flag[2] .   : %d\n", t_node->flag[2]);
    printf("flag[3] *   : %d\n", t_node->flag[3]);
    printf("spec        : %c\n", t_node->spec);
    printf("num         : ");
    printf("%s ", t_node->num);
    printf("\n");
    // while( t_node->result[i] != 0)
    // {
    //     printf("%c ", t_node->result[i]);
    //     i++;
    // }
    printf("result      : %s",t_node->result);
    printf("\n");
    printf("wid         : %d\n", t_node->wid);
    printf("prec        : %d\n", t_node->prec);
    printf("size        : %d\n", t_node->size);
    printf("max_size    : %d\n", t_node->max_size);
    printf("nums        : %d\n\n", t_node->nums);
}

void start_printf(t_format *t_node)
{
    check_percent(t_node);
}

int ft_printf(const char *format, ...)
{
    t_format *t_node;
    t_node = (t_format*)malloc(sizeof(t_format));
    va_start(t_node->ap,format);
    init_firstnode(t_node,(char *)format); //노드초기화
    start_printf(t_node);
    va_end(t_node->ap);
	return(1);
}

int main()
{
    static char *s_hidden = "hi low\0don't print me lol\0";
    // ft_printf("%*.*c  %10.s\n",3,10,'a',"123");
    // ft_printf("%*.*d%10.s",3,10,10,"123");
    
   static char	a01;
    static unsigned char a02;
    static short a03;
    static unsigned short a04;
    static int a05;
    static unsigned int a06;
    static long a07;
    static unsigned long a08;
    static long long a09;
    static unsigned long long a10;
    static char *a11;
    static void *a12;;
    
    // printf("|%10.5c|\n",'1');
    // ft_printf("|%10.5c|\n",'1');
    // ft_printf("|%5.7c|\n",'a');
    // printf("|%5.7c|\n",'a');
    // ft_printf("|%5.7c|\n",0);
    // printf("|%5.7c|\n",0);
   
    // printf("|%10.5s|\n","0061FF1C");
    
    // printf("%p %p %p %p %p %p %p %p %p %p %p %p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
    // ft_printf("%p %p %p %p %p %p %p %p %p %p %p %p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
   

   printf("|%013.10d|\n",-1);
    ft_printf("|%013.10d|\n",-1);
    printf("|%015.14d|\n",-1);
    ft_printf("|%015.14d|\n",-1);


  

    printf("|%p|\n",NULL);
    ft_printf("|%p|\n",NULL);

    printf("|%0.10p|\n",NULL);
    ft_printf("|%0.10p|\n",NULL);

    printf("|%13.10p|\n",&a01);
    ft_printf("|%13.10p|\n",&a01);

    printf("|%5.10p|\n",&a01);
    ft_printf("|%5.10p|\n",&a01);

    printf("|%13.p|\n",&a01);
    ft_printf("|%13.p|\n",&a01);
    
    printf("|%013.p|\n",&a01);
    ft_printf("|%013.p|\n",&a01);
    
    printf("|%-13.p|\n",&a01);
    ft_printf("|%-13.p|\n",&a01);
    
    printf("|%13p|\n",&a01);
    ft_printf("|%13p|\n",&a01);
    
    printf("|%13.p|\n",&a01);
    ft_printf("|%13.p|\n",&a01);
    
    printf("|%05.5p|\n",&a01);
    ft_printf("|%05.5p|\n",&a01);
   

    printf("|%-5.1p|\n",&a01);
    ft_printf("|%-5.1p|\n",&a01);
    printf("|%3.1p|\n",&a01);
    ft_printf("|%3.1p|\n",&a01);


    // printf("|%10.5d|\n",10);
    // ft_printf("|%010.5d%010.5d|\n",123,123);
    // printf("|%010.5d%010.5d|\n",123,123);
    // ft_printf("|%010.2d|\n",123);

//     ft_printf("|%5.7d|\n",123);
//     printf("|%5.7d|\n",123);
//     ft_printf("|%10.2d|\n",123);
//     printf("|%10.2d|\n",123);
//     ft_printf("|%4.3d|\n",123);
//     printf("|%4.3d|\n",123);
//     ft_printf("|%4.2d|\n",123);
//     printf("|%4.2d|\n",123);
//     ft_printf("|%6.4d|\n",123);
//     printf("|%6.4d|\n",123);
//     ft_printf("|%6.12d|\n",111111);
//     printf("|%6.12d|\n",111111);
//     ft_printf("|%5.7d|\n",123);
//     printf("|%5.7d|\n",123);
//     ft_printf("|%10.2d|\n",123);
//     printf("|%10.2d|\n",123);
//     ft_printf("|%4.3d|\n",123);
//     printf("|%4.3d|\n",123);
//     ft_printf("|%4.2d|\n",123);
//     printf("|%4.2d|\n",123);
//     ft_printf("|%6.4d|\n",123);
//     printf("|%6.4d|\n",123);
//     ft_printf("|%6.5d|\n",123);
//     printf("|%6.5d|\n",123);
//     printf("|%10.7d|\n",1234);
//     ft_printf("|%10.7d|\n",1234);
//     printf("|%3.2d|\n",123);
//     ft_printf("|%3.2d|\n",123);
//     ft_printf("|%3.4d|\n",123);
//     printf("|%3.4d|\n",123);
//     printf("|%10.1d|\n", 123456);
//     ft_printf("|%10.1d|\n", 123456);
//     printf("|%5d|\n",-1231232131321);
//     ft_printf("|%5d|\n",-1231232131321);
//     printf("|%10.3d|\n",123);
//     ft_printf("|%10.3d|\n",123);
//     printf("|%10.d|\n",1243);
//     ft_printf("|%10.d|\n",1243);
//     printf("|%3.d|\n",123);
//     ft_printf("|%3.d|\n",123);



//     printf("|%10.1d|\n", 0);
//     ft_printf("|%10.1d|\n", 0);
//     printf("|%5d|\n",0);
//     ft_printf("|%5d|\n",0);
//     printf("|%10.3d|\n",0);
//     ft_printf("|%10.3d|\n",0);
//     printf("|%10.d|\n",0);
//     ft_printf("|%10.d|\n",0);
//     printf("|%3.d|\n",0);
//     ft_printf("|%3.d|\n",0);
//     printf("|%10.d|\n",1);
//     ft_printf("|%10.d|\n",1);
//     printf("|%3.d|\n",1);
//     ft_printf("|%3.d|\n",1);

// //////////////
//     printf("|%8d|\n", 0);
//     ft_printf("|%8d|\n", 0);
//     printf("|%.8d|\n", 0);
//     ft_printf("|%.8d|\n", 0);
    
//     printf("|%-8d|\n", 0);
//     ft_printf("|%-8d|\n", 0);
//     printf("|%-.8d|\n", 0);
//     ft_printf("|%-.8d|\n", 0);

//     printf("|%-8d|\n", 1);
//     ft_printf("|%-8d|\n", 1);
//     printf("|%-.8d|\n", 1);
//     ft_printf("|%-.8d|\n", 1);


//     ft_printf("|%-5.7d|\n",123);
//     printf("|%-5.7d|\n",123);
//     ft_printf("|%-10.2d|\n",123);
//     printf("|%-10.2d|\n",123);
//     ft_printf("|%-4.3d|\n",123);
//     printf("|%-4.3d|\n",123);
//     ft_printf("|%-4.2d|\n",123);
//     printf("|%-4.2d|\n",123);
//     ft_printf("|%-6.4d|\n",123);
//     printf("|%-6.4d|\n",123);
//     ft_printf("|%-6.12d|\n",111111);
//     printf("|%-6.12d|\n",111111);
//     ft_printf("|%-5.7d|\n",123);
//     printf("|%-5.7d|\n",123);
//     ft_printf("|%-10.2d|\n",123);
//     printf("|%-10.2d|\n",123);
//     ft_printf("|%-4.3d|\n",123);
//     printf("|%-4.3d|\n",123);
//     ft_printf("|%-4.2d|\n",123);
//     printf("|%-4.2d|\n",123);
//     ft_printf("|%-6.4d|\n",123);
//     printf("|%-6.4d|\n",123);
//     ft_printf("|%-6.5d|\n",123);
//     printf("|%-6.5d|\n",123);
//     printf("|%-10.7d|\n",1234);
//     ft_printf("|%-10.7d|\n",1234);
//     printf("|%-3.2d|\n",123);
//     ft_printf("|%-3.2d|\n",123);
//     ft_printf("|%-3.4d|\n",123);
//     printf("|%-3.4d|\n",123);
//     printf("|%-10.1d|\n", 123456);
//     ft_printf("|%-10.1d|\n", 123456);
//     printf("|%-5d|\n",-1231232131321);
//     ft_printf("|%-5d|\n",-1231232131321);
//     printf("|%-10.3d|\n",123);
//     ft_printf("|%-10.3d|\n",123);
//     printf("|%-10.d|\n",1243);
//     ft_printf("|%-10.d|\n",1243);
//     printf("|%-3.d|\n",123);
//     ft_printf("|%-3.d|\n",123);
//     printf("|%-8d|\n", NULL);
//     ft_printf("|%-8d|\n", NULL);


//     ft_printf("|%05.7d|\n",12);
//     printf("|%05.7d|\n",12);
//     ft_printf("|%05.7d|\n",0);
//     printf("|%05.7d|\n",0);
//     ft_printf("|%05.7d|\n",1);
//     printf("|%05.7d|\n",1);
//     ft_printf("|%05.7d|\n",0);
//     printf("|%05.7d|\n",0);
//     ft_printf("|%010.2d|\n",0);
//     printf("|%010.2d|\n",0);
//     ft_printf("|%04.3d|\n",0);
//     printf("|%04.3d|\n",0);
//     ft_printf("|%04.2d|\n",0);
//     printf("|%04.2d|\n",0);
//     ft_printf("|%06.4d|\n",0);
//     printf("|%06.4d|\n",0);
//     ft_printf("|%06.5d|\n",0);
//     printf("|%06.5d|\n",0);
//     ft_printf("|%05.7d|\n",0);
//     printf("|%05.7d|\n",0);
//     ft_printf("|%010.2d|\n",0);
//     printf("|%010.2d|\n",0);
//     ft_printf("|%04.3d|\n",0);
//     printf("|%04.3d|\n",0);
//     ft_printf("|%04.2d|\n",0);
//     printf("|%04.2d|\n",0);
//     ft_printf("|%06.4d|\n",0);
//     printf("|%06.4d|\n",0);



    
//     ft_printf("|%05.7s|\n",0);
//     printf("|%05.7s|\n",0);
//     ft_printf("|%010.2s|\n",0);
//     printf("|%010.2s|\n",0);
//     ft_printf("|%04.3s|\n",0);
//     printf("|%04.3s|\n",0);
//     ft_printf("|%04.2s|\n",0);
//     printf("|%04.2s|\n",0);
//     ft_printf("|%06.4s|\n",0);
//     printf("|%06.4s|\n",0);
//     ft_printf("|%06.5s|\n",0);
//     printf("|%06.5s|\n",0);
//     ft_printf("|%05.7s|\n",0);
//     printf("|%05.7s|\n",0);
//     ft_printf("|%010.2s|\n",0);
//     printf("|%010.2s|\n",0);
//     ft_printf("|%04.3s|\n",0);
//     printf("|%04.3s|\n",0);
//     ft_printf("|%04.2s|\n",0);
//     printf("|%04.2s|\n",0);
//     ft_printf("|%06.4s|\n",0);
//     printf("|%06.4s|\n",0);
 

//     ft_printf("|%0.5d|\n",0);
//     printf("|%0.5d|\n",0);

//     ft_printf("|%0.1d|\n",123);
//     printf("|%0.1d|\n",123);

//     ft_printf("|%0.6d|\n",123);
//     printf("|%0.6d|\n",123);

//     ft_printf("|%01.3d|\n",10);
//     printf("|%01.3d|\n",10);

//     ft_printf("|%0.3d|\n",10);
//     printf("|%0.3d|\n",10);
//     ft_printf("|%0.10d|\n",10000);
//     printf("|%0.10d|\n",10000);
//     ft_printf("|%0.3d|\n",10000);
//     printf("|%0.3d|\n",10000);
//     ft_printf("|%03d|\n",10000);
//     printf("|%03d|\n",10000);
//     ft_printf("|%01.3d|\n",10000);
//     printf("|%01.3d|\n",10000);
//     printf("|%03.2d|\n",123);
//     ft_printf("|%03.2d|\n",123);
//     ft_printf("|%03.4d|\n",123);
//     printf("|%03.4d|\n",123);
//     ft_printf("|%0*.*d|\n",0,4,123);
//     printf("|%0*.*d|\n",0,4,123);
//     ft_printf("|%0*.*d|\n",0,0,123);
//     printf("|%0*.*d|\n",0,0,123);



//     printf("%9s\n", s_hidden);
//    ft_printf("%9s\n", s_hidden);
   
//     printf("|%4.4s|\n", NULL);
//     ft_printf("|%4.4s|\n", NULL);
//     ft_printf("|%1.3s|\n","10");
//     printf("|%1.3s|\n","10");
//     ft_printf("|%.3s|\n","10");
//     printf("|%.3s|\n","10");
//     ft_printf("|%.10s|\n","10000");
//     printf("|%.10s|\n","10000");
//     ft_printf("|%.3s|\n","10000");
//     printf("|%.3s|\n","10000");
//      ft_printf("|%3s|\n","10000");
//     printf("|%3s|\n","10000");
//     ft_printf("|%1.3s|\n","10000");
//     printf("|%1.3s|\n","10000");
//     printf("|%3.2s|\n","123");
//     ft_printf("|%3.2s|\n","123");
//     ft_printf("|%3.4s|\n","123");
//     printf("|%3.4s|\n","123");

//     printf("|%-3.2s|\n","123");
//     ft_printf("|%-3.2s|\n","123");
//     ft_printf("|%-3.4s|\n","123");
//     printf("|%-3.4s|\n","123");


//     printf("|%-10.1s|\n", s_hidden);
//     ft_printf("|%-10.1s|\n", s_hidden);
//     printf("|%-5s|\n","-1231232131321");
//     ft_printf("|%-5s|\n","-1231232131321");
//     printf("|%-10.3s|\n","123");
//     ft_printf("|%-10.3s|\n","123");
//     printf("|%-10.s|\n","1243");
//     ft_printf("|%-10.s|\n","1243");
//     printf("|%-3.s|\n","123");
//     ft_printf("|%-3.s|\n","123");
//     printf("|%-8s|\n", NULL);
//     ft_printf("|%-8s|\n", NULL);

//     ft_printf("|%010.5s%010.5s|\n","123","123");
//     printf("|%010.5s%010.5s|\n","123","123");
//     ft_printf("|%010.2s|\n","123");
//     printf("|%010.2s|\n","123");
//     ft_printf("|%0.5s|\n","123");
//     printf("|%0.5s|\n","123");
//     ft_printf("|%0.1s|\n","123");
//     printf("|%0.1s|\n","123");
//     ft_printf("|%0.6s|\n","123");
//     printf("|%0.6s|\n","123");
//     ft_printf("|%01.3s|\n","10");
//     printf("|%01.3s|\n","10");
//     ft_printf("|%0.3s|\n","10");
//     printf("|%0.3s|\n","10");
//     ft_printf("|%0.10s|\n","10000");
//     printf("|%0.10s|\n","10000");
//     ft_printf("|%0.3s|\n","10000");
//     printf("|%0.3s|\n","10000");
//      ft_printf("|%03s|\n","10000");
//     printf("|%03s|\n","10000");
//     ft_printf("|%01.3s|\n","10000");
//     printf("|%01.3s|\n","10000");
//     printf("|%03.2s|\n","123");
//     ft_printf("|%03.2s|\n","123");
//     ft_printf("|%03.4s|\n","123");
//     printf("|%03.4s|\n","123");
//     ft_printf("|%0*.*s|\n",0,4,"123");
//     printf("|%0*.*s|\n",0,4,"123");
//     ft_printf("|%0*.*s|\n",0,0,"123");
//     printf("|%0*.*s|\n",0,0,"123");





    return(0);
}