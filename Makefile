
NAME	=	cub3d

SRCS_L	=	libft/utils_one.c	libft/utils_two.c

SRCS_A	=	src/main.c				src/parsing.c		src/load_texture.c\
			src/parsing_utils.c		src/check_map.c		utils/free.c\
			utils/error.c			src/hook.c			src/all_rays.c\
			src/rotation.c			src/move.c			src/minimap.c\
			src/paint.c				src/ray_cast.c		src/draw_wall.c

OBJS_L	=	${SRCS_L:%.c=%.o}

OBJS_A	=	${SRCS_A:%.c=%.o}

HEADER	=	includes/cub3d.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I${HEADER}

RM		=	 rm -f

.PHONY:		all clean fclean re bonus

all:		${NAME}

%.o: 		%.c ${HEADER}
			@${CC} ${CFLAGS} -c $< -o $@
			@echo "---Compiled "$<" successfully!---"

${NAME}:	${OBJS_A} ${OBJS_L} ${HEADER}
			${CC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS_A} ${OBJS_L}
##			@${CC} ${CFLAGS} -lmlx -lm -lX11 -lXext -lz -I ./libraries/mlx -I ./libraries/mlx/include -L ./libraries/mlx  -I /usr/X11/include -L /usr/X11/lib/ -o ${NAME} ${OBJS_A} ${OBJS_L}
			@echo "Compiled "$(NAME)" successfully!"

clean:
			${RM} ${OBJS_A} ${OBJS_B} ${OBJS_L}

fclean:		clean
			${RM} ${NAME}

re:			fclean all