#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 50

void render_map(void *mlx, void *win, char **map, void **textures)
{
    int row = 0;
    int col;
    int x, y;

    while (map[row])
    {
        col = 0;
        while (map[row][col])
        {
            x = col * TILE_SIZE;
            y = row * TILE_SIZE;

            if (map[row][col] == '1')
                mlx_put_image_to_window(mlx, win, textures[0], x, y);  // Wall
            else if (map[row][col] == '0')
                mlx_put_image_to_window(mlx, win, textures[1], x, y);  // Floor
            else if (map[row][col] == 'C')
                mlx_put_image_to_window(mlx, win, textures[2], x, y);  // Collectible
            else if (map[row][col] == 'E')
                mlx_put_image_to_window(mlx, win, textures[3], x, y);  // Exit
            else if (map[row][col] == 'P')
                mlx_put_image_to_window(mlx, win, textures[4], x, y);  // Player

            col++;
        }
        row++;
    }
}

int main()
{
    void *mlx;
    void *win;
    void *textures[5];  // Array to store textures for each map element
    int img_width, img_height;

    // Initialize MiniLibX
    mlx = mlx_init();
    win = mlx_new_window(mlx, 832, 320, "Tile-Based Map");

    // Load textures (replace with actual image paths)
    textures[0] = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &img_width, &img_height);
    textures[1] = mlx_xpm_file_to_image(mlx, "textures/route.xpm", &img_width, &img_height);
    textures[2] = mlx_xpm_file_to_image(mlx, "textures/coins.xpm", &img_width, &img_height);
    textures[3] = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &img_width, &img_height);
    textures[4] = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &img_width, &img_height);

    // Map with tiles: 1=wall, 0=floor, C=collectible, E=exit, P=player
    char *map[] = {
        "1111111111111111111111111",
        "10000000000C10000000000C1",
        "1010010111111010010111111",
        "1P1011E000001P1011E000001",
        "1111111111111111111111111",
        NULL // Null-terminated array
    };

    // Render the map
    render_map(mlx, win, map, textures);

    // Keep the window open
    mlx_loop(mlx);

    return 0;
}
 
