CC = cc
CCC = clang
GCC = gcc
LIB_PATH = minilibx-linux
OFLAGS = -g \
		 -IInc \
		 -Ilibft \
		 -Ignl \
		 -I$(LIB_PATH) \
		 -Llibft \
		 -Lgnl \
		 -L$(LIB_PATH) \
		 -lft -lgnl \
		 -lmlx -lmlx_Linux \
		 -L/usr/lib \
		 -lXext -lX11 -lm -lz \
		 -Wall -Wextra -Werror 

CFLAGS = -g \
		 -IInc \
		 -I$(LIB_PATH) \
		 -Ilibft \
		 -Ignl \
		 -Llibft \
		 -Lgnl \
		 -L$(LIB_PATH) \
		 -lft -lgnl \
		 -lmlx -lmlx_Linux \
		 -L/usr/lib \
		 -lXext -lX11 -lm -lz \
		 -Wall -Wextra -Werror

NAME = miniRT

SRC = ./main.c \
	  ./rendering/compute_cylinder.c \
	  ./rendering/compute_pixel.c \
	  ./rendering/compute_plane.c \
	  ./rendering/compute_sphere.c \
	  ./rendering/cylinder_intersection.c \
	  ./rendering/find_nearest.c \
	  ./rendering/plane_intersection.c \
	  ./rendering/render.c \
	  ./rendering/sphere_intersection.c \
	  ./parsing/assign_vec.c \
	  ./parsing/ft_atod.c \
	  ./parsing/ft_free.c \
	  ./parsing/ft_free_objects.c \
	  ./parsing/miniRT_parser.c \
	  ./parsing/p_parse_camera.c \
	  ./parsing/p_parse_cylinder.c \
	  ./parsing/p_parse_light.c \
	  ./parsing/p_parse_plane.c \
	  ./parsing/p_parse_sphere.c \
	  ./parsing/valid_element.c \
	  ./utils/color.c \
	  ./utils/event.c \
	  ./utils/init_data.c \
	  ./utils/math_utils.c \

OBJ = $(SRC:.c=.o)

################### VARIABLE ##########################

all: object_file minilibx $(NAME)

object_file:
	@(test ! -e obj && mkdir obj) || echo "obj already exists!!"
	@(test ! -e obj/rendering && mkdir -p obj/rendering) || echo "obj/rendering already exists!!"
	@(test ! -e obj/parsing && mkdir -p obj/parsing) || echo "obj/parsing already exists!!"
	@(test ! -e obj/utils && mkdir -p obj/utils) || echo "obj/utils already exists!!"

libft:
	$(MAKE) -C libft

gnl:
	$(MAKE) -C gnl

minilibx: libft gnl 
	@(test ! -e minilibx-linux.tgz && wget https://cdn.intra.42.fr/document/document/32081/minilibx-linux.tgz) || echo "minilibix already here!!"
	tar -xf minilibx-linux.tgz
	$(MAKE) -C $(LIB_PATH)

%.o: %.c
	$(GCC) $(OFLAGS) -g -c $< -o obj/$@

$(NAME): $(OBJ) libft/libft.a gnl/libgnl.a
	cd obj && gcc $(OBJ) -o ../miniRT $(CFLAGS) -L../libft -L../gnl -L../minilibx-linux -lft -lgnl -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C gnl
	rm -Rf obj

fclean: clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C gnl
	rm -rf $(LIB_PATH)
	rm -f $(NAME)
	rm -f minilibx-linux.tgz

list:
	ls -l *.c

norm: fclean
	norminette

re: fclean all

vpath %.o obj
vpath $(OBJ) obj

.PHONY: all clean fclean re object_file libft gnl minilibx norm list
