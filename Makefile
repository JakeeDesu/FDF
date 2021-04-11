MINILIBX = ./minilibx_macos
SRC = *.c
LIB = -lm -L./libft -lft -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit
NAME = fdf

all :
	make -C $(MINILIBX)
	gcc -o $(NAME) $(SRC) $(LIB)

clean:
	make clean -C $(MINILIBX)
	rm -rf *.o $(NAME)
