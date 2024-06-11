NAME = libft.a
SRCS = 	ft_strlen.c ft_atoi.c ft_split.c ft_putchar_fd.c ft_putnbr_fd.c ft_strlcpy.c ft_putstr_fd.c \
		ft_memmove.c ft_isalpha.c ft_strchr.c ft_isspace.c ft_strlcat.c
	
OBJS = $(SRCS:.c=.o)
CXX = cc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I.

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CXX) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
