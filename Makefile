CC = clang

NAME = RTv1

FLAGS = -Wall -Wextra -Werror -g

IDIR = ./includes

CFLAGS = -I includes \
		 -I libSDL/SDL2.framework/Headers \
		 -I libSDL/SDL2_image.framework/Headers

LIBFT = libft/

LIBVEC = libvec/

SDL2_F	= -framework SDL2 -framework SDL2_image -F ./libSDL/

SDL2_P	= -rpath @loader_path/libSDL/

DIR_S = sources

DIR_O = objects

HEADER = includes

_DEPS = rtv1.h

DEPS = $(patsubst %,$(HEADER)/%,$(_DEPS))

PARSER = init_parser.c \
			parser.c

SOURCES = main.c \
			color.c \
			update.c \
			ray.c \
			error.c \
			cone.c \
			sphere.c \
			cylinder.c \
			plane.c \
			light.c \
			figure.c \
			scene_0.c \
			scene_1.c \
			scene_2.c \
			scene_3.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		make -C $(LIBFT)
		make -C $(LIBVEC)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS) libft/libft.a libvec/libvec.a $(SDL2_P) $(SDL2_F)

obj:
		mkdir -p objects

$(DIR_O)/%.o: $(DIR_S)/%.c $(DEPS)
		$(CC) -c -o $@ $< $(FLAGS) $(CFLAGS)

clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
		make clean -C $(LIBVEC)
		rm -rf $(DIR_O)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)
		make fclean -C $(LIBVEC)

re: fclean all
