CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RFLAGS = rm -f

NAME = push_swap

LIBFT = libft

SRCS = function.c function2.c push_swap.c sort_a.c sort_b.c sort_number.c utils2.c utils.c

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
