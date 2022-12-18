# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalimol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 14:47:13 by akalimol          #+#    #+#              #
#    Updated: 2022/12/17 17:06:44 by akalimol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft.a
LIBFT_WA	= ft

LIBFT_FOLDER	= libft

SRCS		= src/ft_putchar_fd_upd.c src/ft_puthex.c src/ft_putnbr_fd_upd.c \
		  src/ft_putptr.c src/ft_putstr_fd_upd.c src/ft_putunbr.c ft_printf.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror -I

all:		$(NAME)

$(NAME):	$(OBJS)
	mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS):	$(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -l$(LIBFT_WA) -c $(SRCS)
	mv ft_put* src

$(LIBFT):
	make -C $(LIBFT_FOLDER)
	cp $(LIBFT_FOLDER)/$(LIBFT) .

fclean:		clean
	rm -f $(NAME)
	make -C $(LIBFT_FOLDER) fclean

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_FOLDER) clean

re:		fclean $(NAME)

.PHONY:		all clean fclean re
