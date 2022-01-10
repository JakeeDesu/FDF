SRC_FOLDER = ./src
MINILIBX = $(SRC_FOLDER)/minilibx_macos
SRC = $(SRC_FOLDER)/*.c
LIB = -lm -L./$(SRC_FOLDER)/libft -lft -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit
NAME = fdf

all :
	make -C $(MINILIBX)
	gcc -o $(NAME) $(SRC) $(LIB)

clean:
	make clean -C $(MINILIBX)
	rm -rf $(SRC_FOLDER)/*.o 

fclean: clean
	rm -rf $(NAME)

re: fclean all 
