// ulimit -l --> per saber a cada maquina el num max d'archius que pot obrir simultaneament
// valgrind --leak-check=full --show-leak-kinds=all ./p 1char.txt


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    char *line;
    int line_number = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea %d: %s", line_number++, line);
        free(line); // Libera la memoria después de usarla
    }

    close(fd);
    return 0;
}
