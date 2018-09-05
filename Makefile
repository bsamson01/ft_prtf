NAME = libftprintf.a
COMP = gcc -Wall -Wextra -Werror
SRC = ft_printf.c
HEAD = ft_printf.h
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEAD)
	@make -C libft/
	@echo "Libft Successfully compiled"
	@$(COMP) -I libft/include -c $(SRC)
	@echo "Source files successfully compiled"
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)
	@echo "$(NAME) successfully compiled"
clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
