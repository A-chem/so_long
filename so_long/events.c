#include "so_long.h"

void  find_player(D_game *game)
{
 
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player_x = i;
                game->player_y = j;
                return;
            }
            j++;
        }
       i++;
    }
}
void action_player(int key, D_game *game)
{
        find_player(game);
        if(key == W_KEY)
        move_player(game, game->player_x - 1, game->player_y);
        if(key == S_KEY)
        move_player(game, game->player_x + 1, game->player_y);
        if(key == A_KEY)
        move_player(game, game->player_x, game->player_y - 1);
        if(key == D_KEY)
        move_player(game, game->player_x, game->player_y + 1);
        
}
int handle_keypress(int keycode, D_game *game)
{
    if (keycode == ESC_KEY)
      exit_window(game);
    if (keycode == W_KEY)
        action_player(keycode, game);
    if (keycode == S_KEY)
        action_player(keycode, game);  
    if (keycode == A_KEY)
        action_player(keycode, game);   
    if (keycode == D_KEY)
        action_player(keycode, game);
        if ( game ->map[game->player_x][game->player_y] != '1' && game->map[game->player_x][game->player_y] != 'E')
        {
           game->move++;
           printf("move : %d\n", game->move);
        }
    return (0);
}

void move_player(D_game *game, int new_x, int new_y)
{
    
    if (game->map[new_x][new_y] == '0')
    {
       game ->map[game->player_x][game->player_y] = '0';
       game ->map[new_x][new_y] = 'P';
       mlx_put_image_to_window( game->mlx, game->win, game->textures[1], new_x * 50, new_y * 50);
       render_map(game);
    }
    if  (game->map[new_x][new_y] == '1')
     return ;
    if (game->map[new_x][new_y] == 'C')
    {
        game->map[new_x][new_y] = '0';
        mlx_put_image_to_window( game->mlx, game->win, game->textures[4], new_x * 50, new_y * 50);
        game->count_C--;
    }
    if (game->map[new_x][new_y] == 'E' && game->count_C == 0)
    {
        mlx_put_image_to_window( game->mlx, game->win, game->textures[4], new_x * 50, new_y * 50);
        exit_window(game);
    }
    else
        return ;

}
void exit_window(D_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
}
