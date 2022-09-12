# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 13:29:07 by amoriah           #+#    #+#              #
#    Updated: 2022/03/07 15:54:41 by amoriah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	count_and_malloc.c  ft_calloc.c     ft_itoa_decimal.c\
			ft_printf.c         ft_putdecimal.c	ft_puthex.c\
			ft_putpointer.c 	ft_putstr.c		ft_putunsig.c\
			ft_strdup.c         ft_unsig_itoa.c     look_for_type.c\
			check_type.c

HEADER	=	ft_printf.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))


CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all			:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			@ar rcs $(NAME)	$?

%.o		:	%.c $(HEADER)
			@$(CC) $(FLAGS) -c $< -o $@


clean	:
		@rm -f $(OBJ)

fclean	:		clean
		@rm -f $(NAME)

re		:		fclean all