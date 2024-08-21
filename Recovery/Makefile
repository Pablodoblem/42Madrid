NAME = get_next_line.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf


MY_SOURCES =prueba2.c\
						get_next_line_utils.c


OBJS = $(MY_SOURCES:.c=.o)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)

all: $(NAME)

%.o : %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<
clean:
	@$(RM) $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
