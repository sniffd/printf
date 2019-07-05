NAME = libftprintf.a
SRC = ft_printf.c addcharn.c big_hex.c c.c di.c f.c hex.c integer.c o.c octal.c oktotorp.c parse.c s.c x.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a libftprintf.a
	gcc -Wall -Wextra -Werror -c $(SRC) -Ift_printf.h -Ilibft/libft.h
	ar -r $@ $(OBJ)
	ranlib $@
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
clean:
	make -C libft clean
	rm -f $(OBJ)
re: fclean all
