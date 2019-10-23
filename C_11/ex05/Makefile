NAME = do-op

SRCS = srcs/main.c srcs/operator.c

OBJS = ${SRCS:.c=.o}

HEAD = includes

FLAGS = -Wall -Werror -Wextra

.c.o:
	gcc ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): ${OBJS}
	gcc -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all
