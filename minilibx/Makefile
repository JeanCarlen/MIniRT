
NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

CC = gcc

GR	= \033[32;1m
RC	= \033[0m
BG	= \033[42m
BLU	= \033[0;44m

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11 -w

all: $(NOM)

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			@printf "$(BLU) $(RC)"

.m.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.m=.o}
			@printf "$(BG) $(RC)"

$(NOM):	$(OBJ)
		@printf "\n"
		@ar -rc $(NOM) $(OBJ)
		@ranlib $(NOM)

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
