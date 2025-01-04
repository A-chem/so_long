#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct data_map
{   
    int fd;
    size_t num_line;
    char *str;
    char **map;
    size_t count_PE;
    size_t count_C;
}              t_maps;

int check_map(char *pat_str);
char    **ft_split(char *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif 



