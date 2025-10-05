CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRC_DIR = src
SRCS = $(SRC_DIR)/bring_to_top.c $(SRC_DIR)/calculate_median.c $(SRC_DIR)/find_max_pos.c $(SRC_DIR)/free.c $(SRC_DIR)/min_to_top.c $(SRC_DIR)/parse_numbers.c $(SRC_DIR)/push.c $(SRC_DIR)/push_swap.c $(SRC_DIR)/reverse_rotate.c $(SRC_DIR)/rotate.c $(SRC_DIR)/sort.c $(SRC_DIR)/stack_length.c $(SRC_DIR)/swap.c $(SRC_DIR)/validations.c $(SRC_DIR)/atoi.c 

LIBFT_DIR = ./libft

LIBFT_A = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

OBJS = $(SRCS:.c=.o)

# Recompila los .o si Makefile cambia
$(OBJS): Makefile

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT_A)
	
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
