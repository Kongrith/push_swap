NAME = push_swap
LIBFT = libft.a
LIBFTPRINTF= libftprintf.a

CXX = cc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I.

SRCS = push_swap.c turk_algorithm.c three_sorting.c pushswap_utilities.c stack_operation1.c \
	stack_operation2.c stack_operation3.c chk_sorting.c
OBJS = $(SRCS:.c=.o)

SRC_LIBFT = ft_strlen.c ft_atoi.c ft_split.c ft_putchar_fd.c ft_putnbr_fd.c ft_strlcpy.c ft_putstr_fd.c \
		ft_memmove.c
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

SRC_PRINTF = ft_printf.c ft_printchar.c ft_printstr.c ft_printptr.c ft_printdec.c ft_printhex.c ft_printuint.c \
		ft_printf_utilities.c
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

all: $(NAME)
	@echo "built $(NAME) successfully"

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CXX) -o $(NAME) $(OBJS) -L. -lftprintf 

$(LIBFTPRINTF): $(OBJ_PRINTF) $(LIBFT)
	mv $(LIBFT) $(LIBFTPRINTF)
	ar rcs $(LIBFTPRINTF) $(OBJ_PRINTF)

$(LIBFT): $(OBJ_LIBFT)
	ar rcs $(LIBFT) $(OBJ_LIBFT)

%.o: %.c
	$(CXX) $(CCFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJ_LIBFT) $(OBJ_PRINTF)

fclean: clean
	@rm -f $(NAME) $(LIBFT) $(LIBFTPRINTF)

re: fclean all

.PHONY: all clean fclean re
