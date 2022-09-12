# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 13:33:29 by amoriah           #+#    #+#              #
#    Updated: 2022/03/12 17:38:11 by amoriah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

# Colors
WHITE	=	"\033[00m"
BLACK	=	"\033[01;30m"
RED		=	"\033[01;31m"
GREEN	=	"\033[04;32m"
YELLOW	=	"\033[01;33m"
BLUE	=	"\033[01;34m"
MAGENTA	=	"\033[01;35m"
CYAN	=	"\033[01;36m"
TEST_C	=	"\033[02;30m"

DELCOL	= "\033[0m"

SRCS	= 	main.c draw.c read_file.c checks.c utils.c color.c key_hook.c\
 			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
			position.c free_memory.c projections.c
#			 ft_printf/*.c

LIB 	= 	./libft/libft.a ./ft_printf/libftprintf.a

HEADER  = 	fdf.h ./libft/libft.h ./get_next_line/get_next_line.h ./ft_printf/ft_printf.h

RM		= 	rm -f
		 
OBJS	= 	$(SRCS:.c=.o)

CC		= 	gcc

CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS) $(HEADER)
			@$(MAKE) -C ./libft
			@$(MAKE) -C ./ft_printf
			@$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIB)  -o ${NAME}
			@echo $(GREEN) The FDF has been compiled 👏 $(DELCOL)
#			@say -v Milena донт врри

%.o :		 %.c
			@$(CC) -Imlx -c $< -o $@

all:		$(NAME)

clean:
			@$(RM) $(OBJS) 
			@$(MAKE) clean -C ./libft
			@$(MAKE) clean -C ./ft_printf
			@echo $(RED) Obj files has been removed 🤭 $(DELCOL)
#			@say -v Milena 

fclean:		clean
			@$(RM) $(NAME) $(LIB)

re:			fclean all

.PHONY:		all clean fclean re