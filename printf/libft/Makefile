# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalimol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 12:54:42 by akalimol          #+#    #+#              #
#    Updated: 2022/12/12 14:04:04 by akalimol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRC		= ft_atoi.c ft_isascii.c ft_memmove.c ft_striteri.c ft_strmapi.c \
		  ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_substr.c ft_bzero.c \
		  ft_isdigit.c ft_memset.c ft_split.c ft_strtrim.c ft_putendl_fd.c \
		  ft_strlcat.c ft_strnstr.c ft_tolower.c ft_calloc.c ft_isprint.c \
		  ft_strchr.c ft_memchr.c ft_putchar_fd.c ft_strlcpy.c ft_memcpy.c \
		  ft_strrchr.c ft_toupper.c ft_isalnum.c ft_itoa.c ft_isalpha.c \
		  ft_memcmp.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c

BONUS		= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		  ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c

OBJS		= $(SRC:.c=.o)

BONUS_OBJS	= $(BONUS:.c=.o)

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) 

fclean:		clean
	rm -f $(NAME)

re:		fclean $(NAME)

so:
	clang -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BOUNS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

bonus:		$(OBJS) $(BONUS_OBJS)
	ar rcs  $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:		all clean fclean re bonus
