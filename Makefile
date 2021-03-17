# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 07:37:32 by gmorange          #+#    #+#              #
#    Updated: 2021/03/12 08:51:20 by gmorange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFlAGS = -Wall -Werror -Wextra

SRCS = c.c	id.c ft_printf.c	lxux.c	p.c	percent.c printf_untils.c s.c \
	   u.c	n_bonus.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $^ -c -o $@

$(NAME) : $(OBJS)
	make -C libft/
	mv libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)
	make clean -C libft/

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY : all re clean fclean bonus
