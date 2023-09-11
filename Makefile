# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddidenko <ddidenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 13:40:01 by ddidenko          #+#    #+#              #
#    Updated: 2023/08/02 15:03:15 by ddidenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -O2

MAKE_LIB = ar -rcs

SRCS = error_free.c push_command.c swap_command.c rotate_command.c reverse_rotate_command.c \
			push_swap_command.c push_swap_init.c ft_split.c stack_init.c stack_utils.c tiny_sort.c \
			get_next_line.c get_next_line_utils.c  \

PUSH_SWAP = main.c \

CHECKER = checker.c \

OBJS_SRCS = $(SRCS:%.c=%.o)

OBJS_PUSH_SWAP = $(PUSH_SWAP:%.c=%.o)

OBJS_CHECKER = $(CHECKER:%.c=%.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJS_PUSH_SWAP) $(OBJS_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS): $(OBJS_CHECKER) $(OBJS_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS_SRCS)

fclean : clean
	rm -f $(NAME) $(BONUS) 

re : fclean all

rebonus : fclean bonus

both : all bonus

reboth : fclean both

.PHONY : all clean fclean re