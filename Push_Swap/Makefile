CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RFLAGS = rm -f

NAME = push_swap

LIBFT = libft

# SRCS = ft_printf.c ft_check_info.c ft_initnode.c ft_make_d.c ft_make_nd.c ft_make_s.c \
#        ft_output_c.c ft_output_d.c ft_output_p.c ft_output_s.c ft_output_u.c ft_output_x.c \
# 	   ft_start_printf.c ft_to_str.c ft_output_percent.c ft_output_c.c ft_make_c.c \
# 	   ft_maxsize.c ft_utils.c

SRCS = function.c function2.c push_swap.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT).a
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT).a :
	$(MAKE) all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a .

%.o : %.c
	$(CC) $(CFLAGS) -I Libft -c $< -o $@

bonus : all

clean :
	$(MAKE) clean -C $(LIBFT)/
	$(RFLAGS) $(OBJS)

fclean : clean
	$(RFLAGS) $(LIBFT)/$(LIBFT).a
	$(RFLAGS) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
