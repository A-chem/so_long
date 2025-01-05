#include "so_long.h"

int is_valid_map( char *pat_str, D_map *ptr) 
{
 if (ft_strncmp(pat_str + ft_strlen(pat_str) - 4, ".ber", 4) != 0)
    {
        write(1, "Error Extention (.ber)\n", 24);
        return (0);
    }
    if(check_map(pat_str, ptr) == 0)
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
int  is_graphic_mlx(D_map *ptr)
{
    D_mlx mlx;
     int img_width, img_height;

    mlx.mlx = mlx_init();
    if (mlx.mlx == NULL)
        return (0);
    mlx.D_map = *ptr;
    get_map_dimensions(mlx, &mlx.height, &mlx.width);
    mlx.win = mlx_new_window(mlx.mlx,  mlx.width, mlx.height, "So Long Game");
     if (mlx.win == NULL)
        return (0);
        mlx.textures[0] = mlx_xpm_file_to_image(mlx.mlx, "textures/wall.xpm", &img_width, &img_height);
        mlx.textures[1] = mlx_xpm_file_to_image(mlx.mlx, "textures/wall.xpm", &img_width, &img_height);
        mlx.textures[2] = mlx_xpm_file_to_image(mlx.mlx, "textures/collectible.xpm", &img_width, &img_height);
        mlx.textures[3] = mlx_xpm_file_to_image(mlx.mlx, "textures/player.xpm", &img_width, &img_height);
        mlx.textures[4] = mlx_xpm_file_to_image(mlx.mlx, "textures/player.xpm", &img_width, &img_height);
       

     render_map(mlx);

    mlx_loop(mlx.mlx);
    return (0);
}
int main(int argc, char **argv)
{
    char *pat_str;
    D_map D_map;

    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    pat_str = argv[1];
    is_valid_map(pat_str, &D_map);
    is_graphic_mlx(&D_map);
    
    //system("leaks so_long");
    return 0;
}
