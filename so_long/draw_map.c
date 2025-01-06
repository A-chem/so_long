#include "so_long.h"

void get_map_dimensions(D_game *game)
{
    size_t row = 0;
    size_t col;
      
    while (game->map[row])
    {
        col = 0;
        while (game->map[row][col])

        {
            col++;
        }
        row++;
    }
    game->win_width = col * 50;
    game->win_height = row * 50;
    }
void load_img(D_game *game)
{
    int i;

    i = 0;
    while(i < 5)
    {
        if (i == 0)
        game->textures[i] = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->img_width, &game->img_height);
        else if (i == 1)
            game->textures[i] = mlx_xpm_file_to_image(game->mlx, "textures/route.xpm", &game->img_width, &game->img_height);
        else if (i == 2)
            game->textures[i] = mlx_xpm_file_to_image(game->mlx, "textures/coins.xpm", &game->img_width, &game->img_height);
        else if (i == 3)
          game->textures[i] = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->img_width, &game->img_height);
        else if (i == 4)
          game->textures[i] = mlx_xpm_file_to_image(game->mlx, "textures/player1.xpm", &game->img_width, &game->img_height);
          if (!game->textures[i])
                exit(1);
        i++;
    }
}
void render_map(D_game *game)
{
    int x;
    int y; 

    game->row = 0;
    while (game->map[game->row])
    {
        game->col = 0;
        while (game->map[game->row][game->col])
        {
            x = game->col * 50;
            y = game->row * 50;
            if (game->map[game->row][game->col] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->textures[0], x, y);
            else if (game->map[game->row][game->col] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->textures[1], x, y);
            else if (game->map[game->row][game->col] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->textures[2], x, y);  
            else if (game->map[game->row][game->col] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->textures[3], x, y);
            else if (game->map[game->row][game->col] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->textures[4], x, y); 
            game->col++;
        }
        game->row++;
    }
}