#include "so_long.h"


static t_enemy *create_enemy(size_t x, size_t y) {
    t_enemy *new_enemy;
    
    new_enemy = malloc(sizeof(t_enemy));
    if (!new_enemy)
        return NULL;
    new_enemy->enemy_x = x;
    new_enemy->enemy_y = y;
    new_enemy->direction = 1;
    new_enemy->next = NULL;
    return new_enemy;
}
static void add_enemy(size_t x, size_t y, t_game *g) 
{
    t_enemy *new_enemy = create_enemy(x, y);
    if (!new_enemy)
        return ;
    if (!g->enemies)
    {
        g->enemies = new_enemy;
        return ;
    }
    else
    {
        t_enemy *current = g->enemies;
        while (current->next)
        {
           current = current->next;
        }
         current->next = new_enemy;
    }
}

int check_enemy(t_game *g)
{
    size_t i;
    size_t j;


    i = 0;
    g->count_n = 0;
    while  (g->map[i])
    {
        j = 0;
        while (g->map[i][j])
        {
            if (g->map[i][j] == 'N')
            {
                add_enemy(i, j, g);
                g->count_n++;
            }
            j++;
        }
        i++;
    }
    if (g->count_n < 1){
        return (0);
    }
   
    return (1);
}
void move_enemy(t_game *g)
{
    t_enemy *current = g->enemies;
    while (current)
    {
        if (current->direction == 1)
        {
            if (g->map[current->enemy_x + 1][current->enemy_y] == '0')
            {
                g->map[current->enemy_x][current->enemy_y] = '0';
                g->map[current->enemy_x + 1][current->enemy_y] = 'N';
                current->enemy_x++;
            }
            else
                current->direction = 0;
        }
        else
        {
            if (g->map[current->enemy_x - 1][current->enemy_y] == '0')
            {
                g->map[current->enemy_x][current->enemy_y] = '0';
                g->map[current->enemy_x - 1][current->enemy_y] = 'N';
                current->enemy_x--;
            }
            else
                current->direction = 1;
        }
           if( current ->enemy_x == g->player_x && current->enemy_y == g->player_y)
            { 
                printf("Game Over\n");
                exit(0);
            }
        current = current->next;
    }
}
int loop_game(t_game *g)
{
    move_enemy(g);
    render_map(g);
    usleep(1000000);
    return (0);
}
