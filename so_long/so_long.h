#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


#define ESC_KEY 53
#define W_KEY 13
#define A_KEY 0
#define S_KEY 1
#define D_KEY 2


typedef struct Data_game
{
    //data map
    int fd;
    size_t num_line;
    char *str;
    char **map;
    size_t count_PE;
    size_t count_C;
   // data mlx
    void *mlx;
    void *win;
    size_t win_width;  
    size_t win_height;
    int img_width;
    int img_height;
    void *textures[5];
    size_t row;
    size_t col;
    int collectibles;
    int move;
    //data_player
    size_t player_x;
    size_t player_y;
} D_game;


int check_map(char *pat_str, D_game *game);
char    **ft_split(char *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void get_map_dimensions(D_game *game);
void load_img(D_game *game);
void render_map(D_game *game);
int handle_keypress(int keycode, D_game *game);
void action_player(int key, D_game *game);
void find_player(D_game *game);
void move_player(D_game *game, int new_x, int new_y);
void exit_window(D_game *game);
#endif 



