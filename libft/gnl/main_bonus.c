#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);

int main(int argc, char **argv)
{
    int i;
    int files_left;
    int *fds;
    int *active;
    char *line;

    if (argc < 2)
    {
        write(2, "Uso: programa archivo1 archivo2 ...\n", 36);
        return 1;
    }

    fds = malloc((argc - 1) * sizeof(int));
    if (fds == NULL)
        return 1;

    i = 0;
    while (i < argc - 1)
    {
        fds[i] = open(argv[i + 1], O_RDONLY);
        if (fds[i] < 0)
        {
            i = 0;
            while (i < argc - 1)
            {
                if (fds[i] >= 0)
                    close(fds[i]);
                i++;
            }
            free(fds);
            return 1;
        }
        i++;
    }

    active = malloc((argc - 1) * sizeof(int));
    if (active == NULL)
    {
        i = 0;
        while (i < argc - 1)
        {
            close(fds[i]);
            i++;
        }
        free(fds);
        return 1;
    }

    i = 0;
    while (i < argc - 1)
    {
        active[i] = 1;
        i++;
    }

    files_left = argc - 1;

	while (files_left > 0)
	{
		i = 0;
		while (i < argc - 1)
		{
		    if (active[i] == 1)
		    {
		        line = get_next_line(fds[i]);
		        if (line == NULL)
		        {
		            close(fds[i]);
		            active[i] = 0;
		            files_left = files_left - 1;
		        }
		        else
		        {
		            printf("%s", line);
		            free(line);
		        }
		    }
		    i++;
		}
	}

    free(fds);
    free(active);
    return 0;
}

