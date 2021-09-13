# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 17:30:25 by ji-park           #+#    #+#              #
#    Updated: 2021/09/13 17:30:27 by ji-park          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

CC := gcc
CFLAGS = -Wall -Wextra -Werror -pthread
#CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address 
INCLUDE := -I./includes
RM := rm -rf
.SUFFIXES : .c .o

SRCS := main.c ft_isdigit.c ft_atoi.c routine.c utils.c
OBJ_DIR := ./obj
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all : $(NAME)
	@echo "\033[32m(つ ◕▽◕)つ    philo is complete!    c(◕▽◕ c)\033[0m"

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $(NAME)
	@echo "\033[32m(つ >_<)つ philo has been compiled! c(>_< c)\033[0m"

$(OBJ_DIR)/%.o : ./%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(RM) $(OBJ_DIR)/*.o

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re