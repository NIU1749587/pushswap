NAME = get_next_line.a
NAME_BONUS = get_next_line_bonus.a

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
AR = ar rcs

BUFFER_SIZE ?= 42

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)

# Regla para compilar archivos .c en .o para la versión bonus
# Se usa un prefijo diferente para evitar conflictos con la versión obligatoria
_bonus.o: get_next_line_bonus.c
	$(CC) $(CFLAGS) -c $< -o $@

get_next_line_utils_bonus.o: get_next_line_utils_bonus.c
	$(CC) $(CFLAGS) -c $< -o $@

# Reglas de limpieza
clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

