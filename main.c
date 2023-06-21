#include "monty.h"
glob_vars gv = {NULL, NULL, NULL};
int main(int argc, char *argv[])
{
    int f = 0;
    size_t size = 0;
    ssize_t lines = 1;
    unsigned int l = 0;
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    gv.file = fopen(argv[1], "r");
    if (gv.file == NULL)
    {
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
    }

    while (lines > 0)
    {
        gv.line = NULL;
        lines = getline(&(gv.line), &size, gv.file);
        if (lines > 0)
            f = handle_cmd(gv.line, ++l, &gv.head);
        if (f == 1)
        {
            dprintf(STDERR_FILENO, "L%u: usage: push integer\n", l);
            fclose(gv.file);
            free(gv.line);
            free_dlistint(gv.head);
            exit(EXIT_FAILURE);
        }
        if (f == 2)
        {
            fclose(gv.file);
            free(gv.line);
            free_dlistint(gv.head);
            exit(EXIT_FAILURE);
        }
        free(gv.line);
    }
    fclose(gv.file);

    return (0);
}
