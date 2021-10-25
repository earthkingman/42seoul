# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:53:35 by ji-park           #+#    #+#              #
#    Updated: 2021/10/25 11:06:27 by ji-park          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= pipex

NAME_B			= pipex_bonus

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

INCS			= -Ilibft -I.

SRCS_DIR		= srcs
SRCS_NAME		= pipex.c \
					utils.c

SRCS			= $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))

SRCS_B_DIR		= srcs_bonus
SRCS_B_NAME		= pipex_bonus.c \
					utils_bonus.c

SRCS_B			= $(addprefix $(SRCS_B_DIR)/, $(SRCS_B_NAME))

OBJS_DIR		= objs
OBJS			= $(addprefix $(OBJS_DIR)/, $(SRCS_NAME:.c=.o))

OBJS_B_DIR		= objs_bonus
OBJS_B			= $(addprefix $(OBJS_B_DIR)/, $(SRCS_B_NAME:.c=.o))

LIB_DIR			= libft
LIB_NAME		= ft
LIB				= $(addprefix $(LIB_DIR)/, libft.a)

$(NAME)			: $(LIB) $(OBJS)
					$(CC) $(CFLAGS) $(INCS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS) -o $@

$(NAME_B)		: $(LIB) $(OBJS_B)
					$(CC) $(CFLAGS) $(INCS) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS_B) -o $@

$(LIB)			:
					$(MAKE) -C $(LIB_DIR) all
					$(MAKE) -C $(LIB_DIR) bonus

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJS_B_DIR)/%.o : $(SRCS_B_DIR)/%.c
					mkdir -p $(OBJS_B_DIR)
					$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all 			: $(NAME)

clean			:
					$(MAKE) -C $(LIB_DIR) clean
					rm -rf $(OBJS_DIR) $(OBJS_B_DIR)

fclean			:
					$(MAKE) -C $(LIB_DIR) fclean
					rm -rf $(NAME) $(NAME_B) $(OBJS_DIR) $(OBJS_B_DIR)

bonus			: $(NAME_B)

re				: fclean all

.PHONY			: all clean fclean re bonus