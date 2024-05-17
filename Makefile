NAME = push_swap
LIBFTNAME = libft.a
LIBFTPRINTF= libftprintf.a

CXX = cc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I.

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

SRC_LIBFT = ft_atoi.c
OBJ_LIBFT = $(SRCS:.c=.o)

SRC_LIBFTPRINTF = ft_printf.c ft_printchar.c ft_printstr.c ft_printptr.c ft_printdec.c ft_printhex.c ft_printuint.c \
		ft_utilities.c
OBJ_LIBFTPRINTF = $(SRCS:.c=.o)

all: $(NAME)
	@echo "built $(NAME) successfully"

$(NAME): $(OBJS) $(LIBFTNAME) $(LIBFTPRINTF)
	$(CXX) -o $@ $^ -L. -L. -lft lftprintf

$(LIBFTNAME): $(OBJ_LIBFT)
	@cc -c ft_atoi.c -o ft_atoi.o
	@ar rcs $(LIBFTNAME) ft_atoi.o

$(LIBFTPRINTF): $(OBJ_FTPRINTF)
	@cc -c ft_atoi.c -o ft_atoi.o
	@ar rcs $(LIBFTPRINTF) ft_atoi.o

%.o: %.c
	$(CXX) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJ_LIBFT)

fclean: clean
	@rm -f $(NAME) $(LIBFTNAME)

re: fclean all

.PHONY: all clean fclean re
