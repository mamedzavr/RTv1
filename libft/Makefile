# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 12:56:38 by wqarro-v          #+#    #+#              #
#    Updated: 2019/07/08 12:11:45 by wqarro-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c

HEAD = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	gcc -g $(FLAGS) -c $(SRCS) -I $(HEAD)
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
