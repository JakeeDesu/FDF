# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iberchid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 16:17:49 by iberchid          #+#    #+#              #
#    Updated: 2018/10/12 10:00:48 by iberchid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = *.c
OFILES = *.o
NAME = libft.a

all : $(NAME)

$(NAME) :
	gcc -Werror -Wall -Wextra -c $(SRCS)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
