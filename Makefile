NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_strcpy.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_base.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstlast.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo $(NAME) has been compiled
.c.o:
	gcc $(CFLAGS) -c $<

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJ)
	@echo All object files have been removed

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) has been removed

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJ)
	@ar rc $(NAME) $(BONUS_OBJ) $(OBJECTS)
	@ranlib $(NAME)
	@echo $(NAME) with bonus part has been compiled
