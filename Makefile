NAME = test

CMD = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fsanitize=undefined -D BUFFER_SIZE=10

SRCS = get_next_line.c\
		get_next_line_utils.c\
		test.c\

all:
	$(CMD) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f *.o test

re: fclean all

.PHONY: all clean fclean re
