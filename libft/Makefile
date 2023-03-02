# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 10:51:40 by fmalizia          #+#    #+#              #
#    Updated: 2023/03/02 11:03:57 by fmalizia         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c ft_tolower.c ft_toupper.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_isupper.c \
				ft_islower.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c ft_strnstr.c \
				ft_bzero.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
				ft_itoa.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_print_char.c ft_print_hex.c \
				ft_print_int.c ft_print_ptr.c ft_print_str.c ft_print_unsigned_int.c ft_printf.c
OBJS		= ${SRCS:.c=.o}

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

BONUS_OBJS	= ${BONUS:.c=.o}

NAME		= libft.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

GR	= \033[32;1m
RC	= \033[0m
BG = \033[42m

.c.o:
				@printf "$(BG) $(RC)"
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	start ${OBJS}
				@ar rc ${NAME} ${OBJS}
				@printf "\n"

all:			${NAME}

clean:
			@printf "**Deleting Libft  **\n"
			@${RM} $(OBJS) ${BONUS_OBJS}

fclean:		clean
			@${RM} ${NAME}

re:				fclean all

bonus:		@${OBJS} ${BONUS_OBJS}
			@ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

start:
		@printf "//COMPILING LIBFT//\n"

.PHONY: 	all clean fclean re	bonus start
