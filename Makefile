SRCS= libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c  libft/ft_putchar_fd.c libft/ft_split.c \
	libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_atoi.c libft/ft_isalpha.c \
	libft/ft_itoa.c libft/ft_memcpy.c  libft/ft_putendl_fd.c libft/ft_strlcpy.c \
	libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c   libft/ft_isascii.c \
	libft/ft_memmove.c libft/ft_putnbr_fd.c libft/ft_strrchr.c \
	libft/ft_toupper.c libft/ft_calloc.c  libft/ft_isdigit.c libft/ft_memchr.c  libft/ft_memset.c  \
	libft/ft_putstr_fd.c libft/ft_strjoin.c libft/ft_strmapi.c libft/ft_strtrim.c libft/ft_striteri.c \
	libft/../mandatory/utils1.c libft/get_next_line_utils.c
OBJS= $(SRCS:.c=.o)
CC= gcc
RM= rm -f
LIBFT= libft.a
CFLAGS= -Wall -Wextra -Werror

NAME= pipex

all: $(NAME)

$(NAME): lib
	$(CC) $(CFLAGS) mandatory/pipex.c $(LIBFT) -o pipex

clean:
	rm -rf libft/*.o *.a mandatory/*.o bonus/*.o

fclean: clean
	$(RM) pipex

bonus: lib
	$(CC) $(CFLAGS) bonus/pipex_bonus.c libft/get_next_line.c $(LIBFT) -o pipex

lib: $(OBJS)
	ar rcs libft.a $(OBJS)

.PHONY:	all clean fclean re bonus lib
