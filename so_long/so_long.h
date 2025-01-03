#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct data_map
{   
    int fd;
    int num_line;
    char *str;
    char **map;
    int count_PE;
    int count_C;
}              t_maps;

int check_map(char *pat_str);
char    **ft_split(char *s, char c);

#endif 



