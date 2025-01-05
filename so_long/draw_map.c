#include "so_long.h"

void get_map_dimensions(D_mlx mlx, size_t *height, size_t *width)
{
    size_t row = 0;
    size_t col;
      
    while (mlx.D_map.map[row])
    {
        col = 0;
        while (mlx.D_map.map[row][col])

        {
            col++;
        }
        row++;
    }
    *width = col * TILE_SIZE;
    *height = row * TILE_SIZE;
    }
void render_map(D_mlx mlx)
{
    int x;
    int y;
   
    mlx.row = 0;
    while (mlx.D_map.map[mlx.row])
    {
        mlx.col = 0;
        while (mlx.D_map.map[mlx.row][mlx.col])
        {
            x = mlx.col * TILE_SIZE;
            y = mlx.row * TILE_SIZE;
            if (mlx.D_map.map[mlx.row][mlx.col] == '1')
                mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.textures, x, y);  
            else if (mlx.D_map.map[mlx.row][mlx.col] == '0')
                mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.textures +1, x, y);  
            else if (mlx.D_map.map[mlx.row][mlx.col] == 'C')
                mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.textures +2, x, y);  
            else if (mlx.D_map.map[mlx.row][mlx.col] == 'E')
                mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.textures +3, x, y);  
            else if (mlx.D_map.map[mlx.row][mlx.col] == 'P')
                mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.textures +4, x, y); 
            mlx.col++;
        }
        mlx.row++;
    }
}
