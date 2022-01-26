# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 14:14:47 by taehyeok          #+#    #+#              #
#    Updated: 2022/01/23 14:21:40 by taehyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror
INCS = includes

SRCS = ./srcs/check_f.c ./srcs/dict_f.c ./srcs/free_f.c ./srcs/is_error.c ./srcs/is_f.c ./srcs/is_f2.c ./srcs/key_f.c ./srcs/main.c ./srcs/pars_f.c ./srcs/str_f.c
OBJS = ${SRCS:.c=.o}

NAME = rush-02

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c -I $(INCS) $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
