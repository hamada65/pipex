SRCS =  srcs/mandatory/pipex.c \
		srcs/mandatory/pipex_utils.c \
		srcs/libft/ft_isalpha.c srcs/libft/ft_isdigit.c srcs/libft/ft_isalnum.c srcs/libft/ft_isascii.c srcs/libft/ft_isprint.c srcs/libft/ft_strlen.c \
		srcs/libft/ft_toupper.c srcs/libft/ft_tolower.c srcs/libft/ft_strchr.c srcs/libft/ft_strrchr.c srcs/libft/ft_strncmp.c \
		srcs/libft/ft_memcpy.c srcs/libft/ft_memmove.c srcs/libft/ft_memset.c srcs/libft/ft_memcmp.c srcs/libft/ft_memchr.c srcs/libft/ft_bzero.c \
		srcs/libft/ft_strnstr.c srcs/libft/ft_strlcpy.c srcs/libft/ft_strlcat.c srcs/libft/ft_atoi.c srcs/libft/ft_strdup.c srcs/libft/ft_calloc.c \
		srcs/libft/ft_substr.c srcs/libft/ft_strjoin.c srcs/libft/ft_split.c srcs/libft/ft_itoa.c srcs/libft/ft_strmapi.c \
		srcs/libft/ft_putchar_fd.c srcs/libft/ft_putstr_fd.c srcs/libft/ft_putendl_fd.c \
		srcs/libft/ft_putnbr_fd.c srcs/libft/ft_strtrim.c  srcs/libft/ft_striteri.c
SRCS_BONUS =  srcs/bonus/pipex_bonus.c \
		srcs/bonus/pipex_utils_bonus.c \
		srcs/bonus/pipex_here_doc.c \
		srcs/bonus/get_next_line_bonus.c \
		srcs/bonus/get_next_line_utils_bonus.c \
		srcs/libft/ft_isalpha.c srcs/libft/ft_isdigit.c srcs/libft/ft_isalnum.c srcs/libft/ft_isascii.c srcs/libft/ft_isprint.c srcs/libft/ft_strlen.c \
		srcs/libft/ft_toupper.c srcs/libft/ft_tolower.c srcs/libft/ft_strchr.c srcs/libft/ft_strrchr.c srcs/libft/ft_strncmp.c \
		srcs/libft/ft_memcpy.c srcs/libft/ft_memmove.c srcs/libft/ft_memset.c srcs/libft/ft_memcmp.c srcs/libft/ft_memchr.c srcs/libft/ft_bzero.c \
		srcs/libft/ft_strnstr.c srcs/libft/ft_strlcpy.c srcs/libft/ft_strlcat.c srcs/libft/ft_atoi.c srcs/libft/ft_strdup.c srcs/libft/ft_calloc.c \
		srcs/libft/ft_substr.c srcs/libft/ft_strjoin.c srcs/libft/ft_split.c srcs/libft/ft_itoa.c srcs/libft/ft_strmapi.c \
		srcs/libft/ft_putchar_fd.c srcs/libft/ft_putstr_fd.c srcs/libft/ft_putendl_fd.c \
		srcs/libft/ft_putnbr_fd.c srcs/libft/ft_strtrim.c  srcs/libft/ft_striteri.c
NAME = pipex
NAME_BONUS = pipex_bonus
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all: ${NAME}

bonus: ${NAME_BONUS}

.SECONDARY: ${OBJS} ${OBJS_BONUS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${NAME_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all