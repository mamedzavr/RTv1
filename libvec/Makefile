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
