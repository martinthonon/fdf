SRCS_DIR	= ./src/

SRCS_FILE	= main.c utils.c events.c engine.c file_checker.c

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