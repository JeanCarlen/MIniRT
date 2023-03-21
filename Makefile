# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 12:41:46 by nnemeth           #+#    #+#              #
#    Updated: 2023/03/21 11:52:57 by fmalizia         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

LIB			= Libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g3 #-fsanitize=address 

SRCS		=	convert_tab.c forms.c forms2.c forms3.c forms4.c \
				free_error.c init_parsing.c init.c inter.c inter_2.c \
				jeanchoisitunnom.c launch.c main.c parsing_file_utils.c \
				parsing_file_utils2.c parsing_file_utils3.c quit.c readfile.c \
				secondsplit.c splitstring.c utils.c vectors.c vectors2.c vectors3.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

NAME		= miniRT

FRAMEWORK	= -framework OpenGL -framework AppKit

MLXPATH		= ./minilibx/

INCLUDEMLX	= -I ${MLXPATH}

LMLX		= -L ${MLXPATH} -lmlx

GR	= \033[32;1m
RC	= \033[0m
BG	= \033[42m

all:	start ${NAME}
.c.o:
				@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
				@printf "$(BG) $(RC)"

$(NAME): ${OBJS}
		@printf "\n"
		@$(MAKE) -C ${MLXPATH}
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