#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define TILE_SIZE 64

typedef struct data_map
{   
    int fd;
    size_t num_line;
    char *str;
    char **map;
    size_t count_PE;
    size_t count_C;
}              D_map;
typedef struct data_mlx
{
    void *mlx;
    void *win;
    void *image;
    size_t width;  
    size_t height;
    void *textures[5];
    size_t row;
    size_t col;
    D_map D_map;
}           D_mlx;



int check_map(char *pat_str, D_map *ptr);
char    **ft_split(char *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void render_map(D_mlx mlx);
void get_map_dimensions(D_mlx mlx, size_t *height, size_t *width);

#endif 



