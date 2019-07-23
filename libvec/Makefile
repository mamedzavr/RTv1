# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 11:58:12 by wqarro-v          #+#    #+#              #
#    Updated: 2019/07/23 11:58:14 by wqarro-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a

SRCS = *.c

HEAD = libvec.h

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
