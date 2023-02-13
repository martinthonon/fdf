SRCS_DIR	= ./srcs/

SRCS_FILE	= main.c utils.c \
 				mlx.c engine.c engine_utils.c checker.c checker_utils.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILE))

MLX			= -lmlx -framework OpenGL -framework AppKit

LIBFT		= lib/libft/libft.a

OBJS	= ${SRCS:.c=.o}

NAME	= fdf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS)
	make -C lib/libft
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) $(LIBFT)

all :	$(NAME)

clean:
	make fclean -C lib/libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re