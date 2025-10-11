CC = cc

NAME = pushswap

SOURCE = bring_to_top.c\
				calculate_median.c\
				find_max_and_min.c\
				main.c\
				parse_num.c\
				push.c\
				revrotate.c\
				rotate.c\
				sort.c\
				swap.c

OBJ = $(SOURCE:%.c=%.o)

AR = ar -rc

CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(AR) $(NAME) $(OBJ)
	
%.o: %.c pushswap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -sC $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all fclean clean re
