/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:30:50 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/11 14:58:37 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_enemy	*create_enemy(size_t x, size_t y)
{
	t_enemy	*new_enemy;

	new_enemy = malloc(sizeof(t_enemy));
	if (!new_enemy)
		return (NULL);
	new_enemy->enemy_x = x;
	new_enemy->enemy_y = y;
	new_enemy->direction = 1;
	new_enemy->horizontal_direction = 1;
	new_enemy->next = NULL;
	return (new_enemy);
}

static void	add_enemy(size_t x, size_t y, t_game *g)
{
	t_enemy	*new_enemy;
	t_enemy	*current;

	new_enemy = create_enemy(x, y);
	if (!new_enemy)
		return ;
	if (!g->enemies)
	{
		g->enemies = new_enemy;
		return ;
	}
	else
	{
		current = g->enemies;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_enemy;
	}
}

int	check_enemy(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	g->count_n = 0;
	while (g->map[i])
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
	if (g->count_n < 1)
		return (0);
	return (1);
}

void	move_enemy(t_game *g)
{
	static int	speed = 0;
	t_enemy		*current;

	speed++;
	if (speed % 20 != 0)
		return ;
	current = g->enemies;
	while (current)
	{
		move_direction(g, current);
		move_horizontal(g, current);
		if (current ->enemy_x == g->player_x && current->enemy_y == g->player_y)
		{
			free_enemies(g->enemies);
			exit(0);
		}
		current = current->next;
	}
}

int	loop_game(t_game *g)
{
	move_enemy(g);
	render_map(g);
	display_move_count(g);
	return (0);
}
