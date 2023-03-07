# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 12:41:46 by nnemeth           #+#    #+#              #
#    Updated: 2023/03/07 16:05:21 by fmalizia         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

LIB			= Libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g3 #-fsanitize=address 

SRCS		= $(wildcard *.c)

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

NAME		= miniRT

FRAMEWORK	= -framework OpenGL -framework AppKit

MLXPATH		= ./minilibx/

INCLUDEMLX	= -I ${MLXPATH}

LMLX		= -L ${MLXPATH} -lmlx

GR	= \033[32;1m
RC	= \033[0m
BG = \033[42m

all:	start ${NAME}
.c.o:
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
				@printf "$(BG)  $(RC)"

$(NAME): ${OBJS}
		@printf "\n"
		@$(MAKE) -s -C ${MLXPATH}
		@$(MAKE) -C ./Libft
		@$(CC) $(CFLAGS) $(FRAMEWORK) $(SRCS) $(LMLX) $(LIB) -o $(NAME)

clean:
		@printf "**Deleting objects**\n"
		@${RM} $(OBJS)

fclean:	clean
		@make fclean -C Libft
		@printf "**Deleting miniRT **\n"
		@${RM} ${NAME}

re:		fclean all

reset: fclean
		@printf "**Deleting MLX    **\n"
		@make -s clean -C ${MLXPATH}

start:
		@printf "//COMPILING miniRT//\n"

.Phony: all clean re reset start