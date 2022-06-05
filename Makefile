NAME	=	fdf

HEADER	= fdf.h

# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m

CC = gcc

LIBFT = cd ./Libft && make

FLAGS = -Wall -Wextra -Werror

MLX_INC = -I /usr/local/include/mlx.h

MLX_LIB = -L /usr/local/lib/ -lmlx

FRAMEWORKS = -framework OpenGl -framework Appkit

%.o : %.c
	${CC} -I. -o $@ -c $? ${FLAGS}

SRCS = create_map.c create_map_utils.c get_next_line.c get_next_line_utils.c bresendraw.c math_perso.c \
matrix_operations.c set_basic_values.c init_controls.c mlx_visual.c controls_modify.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${LIBFT}
	${CC} ${FLAGS} ${MLX_INC} ./Libft/libft.a ${MLX_LIB} ${FRAMEWORKS} -fsanitize=address -o ${NAME} ${OBJS}
	@printf "${B_CYAN}{${NAME}} Compilation done${NONE}\n"

clean:
		@cd ./Libft && make clean
		rm -f ${OBJS}
		@printf "${B_GREEN}{${NAME}} Cleansed${NONE}\n"

fclean:
		@cd ./Libft && make fclean
		rm -f ${OBJS}
		rm -f ${NAME}
		@printf "${B_GREEN}{${NAME}} Fcleansed${NONE}\n"

re: fclean all

.PHONY: clean fclean re
