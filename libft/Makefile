NAME = libftprintf.a

SRC =	ft_atoi.c \
        ft_bzero.c \
        ft_calloc.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_memset.c \
		ft_strncmp.c \
        ft_strchr.c \
        ft_strdup.c \
        ft_strlcat.c \
        ft_strlcpy.c \
        ft_strlen.c \
        ft_strnstr.c \
        ft_strrchr.c \
        ft_tolower.c \
        ft_toupper.c \
		ft_itoa.c \
		ft_split.c \
		ft_newsplit.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line_utils.c \
		get_next_line.c

SRC_BONUS = ft_lstnew_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstmap_bonus.c

PRF_SRC =	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_puts.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

PRF_OBJ = $(PRF_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ) $(PRF_OBJ)
	ar rcs $(NAME) $(OBJ) $(PRF_OBJ)

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

%.o : %.c libft.h
	cc -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(PRF_OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean