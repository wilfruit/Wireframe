NAME	=	fdf.out

${NAME} : 
	gcc -I /usr/local/include/mlx.h create_map.c create_map_utils.c get_next_line.c get_next_line_utils.c bresendraw.c math_perso.c matrix_operations.c set_basic_values.c init_controls.c mlx_visual.c controls_modify.c libft.a -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit -fsanitize=address

all : ${NAME}
