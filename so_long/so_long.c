#include "so_long.h"

static int is_valid_map( char *pat_str, D_game *game) 
{
 if (ft_strncmp(pat_str + ft_strlen(pat_str) - 4, ".ber", 4) != 0)
    {
        write(1, "Error Extention (.ber)\n", 24);
        return (0);
    }
    if(check_map(pat_str, game) == 0)
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
static int  is_graphic_mlx(D_game *game)
{
    game->mlx = mlx_init();
    if (game->mlx == NULL)
        return (0);  
    get_map_dimensions(game);
    game->win = mlx_new_window(game->mlx,  game->win_width, game->win_height, "So Long Game");
    if(!game->win)
        return (0);
    load_img(game);
    render_map(game);
    game->move = 0;
   mlx_key_hook(game->win, handle_keypress, game);

    mlx_loop(game->mlx);
    return (0);
}
int main(int argc, char **argv)
{
    char *pat_str;
    D_game game;
    

    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    pat_str = argv[1];
    is_valid_map(pat_str, &game);
    is_graphic_mlx(&game);

   // system("leaks so_long");
    return 0;
}
