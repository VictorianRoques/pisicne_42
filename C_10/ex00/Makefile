NAME = ft_display_file

SRCS = srcs/main.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra

.c.o:
	gcc $(FLAGS) -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS}
	gcc -o ${NAME} ${OBJS}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}

re: flclean all
