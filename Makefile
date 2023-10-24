NAME =	libftprintf.a

INCL = libftprintf.h

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_process.c ft_my_strchr.c ft_print_char.c ft_print_str.c ft_digit.c ft_puthex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		
%.o: %.c $(INCL) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re