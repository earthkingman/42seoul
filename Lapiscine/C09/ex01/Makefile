CC = gcc
CFLAGS = -Wall -Wextra -Werror
RFLAGS = rm -f

TARGET = libft.a
INCS = includes
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJECTS = $(SRCS:.c=.o)

all: $(TARGET)

.c.o :

	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(TARGET) : $(OBJECTS)
	ar cr $(TARGET) $(OBJECTS)

clean:
	$(RFLAGS) $(OBJECTS)

fclean: clean
	$(RFLAGS) $(TARGET)

re: fclean all
