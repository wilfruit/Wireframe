#include"fdf.h"

int **allocate_int_tab(int x, int y)
{
    int **ultab;
    int i;

    i = 0;
    ultab = (int **)malloc(sizeof(int **) * (y + 1));
    if (!ultab)
        return NULL;
    while (i <= y)
    {
        ultab[i] = (int *)malloc(sizeof(int *) * (x + 1));
        if (!ultab[i])
            return NULL;
        i++;
    }
    return (ultab);
}

int  lines_counter(char *file)
{
    int  lines_nb;
    int     i;

    i = 0;
    lines_nb = 0;
    while (file[i])
    {
        if (file[i] == '\n')
            lines_nb++;
        i++;
    }
    return (lines_nb);
}

int  rows_counter(char *file)
{
    int  rows_nb;
    int     i;
    int     switch_space;

    i = 0;
    rows_nb = 0;
    switch_space = 0;
    while (file[i] != '\n' )
    {
        if (switch_space == 1 && file[i] == ' ')
            switch_space = 0;
        if (switch_space == 0 && file[i] != ' ')
        {
            switch_space = 1;
            rows_nb++;
        }
        i++;
    }
    return (rows_nb);
}

void    ft_print_tab(int **tab)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 11)
    {
        j = 0;
        while (j < 19)
        {
            printf("%i  ", tab[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}