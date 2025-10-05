CC = cc

NAME = libft.a

SOURCE = ft_isdigit.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_isnum.c\
				ft_strlen.c\
				ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_strchr.c\
				ft_strncmp.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strnstr.c\
				ft_atoi.c\
				ft_atof.c\
				ft_atol.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_itoa.c\
				ft_strrchr.c\
				ft_strmapi.c\
				ft_striteri.c\
				ft_split.c

OBJ = $(SOURCE:%.c=%.o)

AR = ar -rc

CFLAGS = -Wall -Werror -Wextra

GNL_DIR = gnl
GNL_A = $(GNL_DIR)/get_next_line.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF_A = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(GNL_A) $(FT_PRINTF_A)
	$(AR) $(NAME) $(OBJ)
	
%.o: %.c libft.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	
$(GNL_A):
	$(MAKE) -C $(GNL_DIR)
	
$(FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -sC $(GNL_DIR) clean
	$(MAKE) -sC $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(GNL_DIR) fclean
	$(MAKE) -sC $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all fclean clean re
