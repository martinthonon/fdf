SRCS_DIR	= ./srcs/

SRCS_FILE	= main.c utils.c \
 				mlx.c mlx_utils.c \
 				engine.c engine_utils.c \
 				checker.c checker_utils.c \
 				bresenham.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILE))

MLX			= -lmlx -framework OpenGL -framework AppKit

LIBFT		= lib/libft/libft.a

OBJS	= ${SRCS:.c=.o}

NAME	= fdf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -O3

#SANITIZE	= -fsanitize=address -g -O1 -fno-omit-frame-pointer

RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):	$(OBJS)
	make bonus -C lib/libft
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) $(LIBFT)

all :	$(NAME)

clean:
	make fclean -C lib/libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re