#include "so_long.h"

int is_valid_map( char *pat_str)
{
 if (ft_strncmp(pat_str + ft_strlen(pat_str) - 4, ".ber", 4) != 0)
    {
        write(1, "Error Extention (.ber)\n", 24);
        return (0);
    }
    if(check_map(pat_str) == 0)
    {
        write(1, "Your map not valid !!!\n", 24);
        return (0);
    }
    else
    {
        write(1, "Your map is valid !!!\n", 23);
        return (0);
    }
}
void *is_graphic_mlx()
{
    void *mlx;
    void *win;
    void *image;
    int width ;
    int height ;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "So Long Game");
    image = mlx_xpm_file_to_image(mlx, "open.xpm", &width, &height);
    mlx_put_image_to_window(mlx, win, image, 0, 100);

    mlx_loop(mlx);
    return (mlx);
}
int main(int argc, char **argv)
{
    char *pat_str;
   

    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    pat_str = argv[1];
    is_valid_map(pat_str);
    is_graphic_mlx();
    //system("leaks so_long");
    return 0;
}
