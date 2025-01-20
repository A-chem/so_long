/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:34:49 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/10 11:43:13 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	anima_player(t_game *g, int x, int y)
{
	if (g->player_anim == 0 || g->player_anim == 2)
		mlx_put_image_to_window(g->mlx, g->win, g->textures[4], x, y);
	if (g->player_anim == 1)
		mlx_put_image_to_window(g->mlx, g->win, g->textures[5], x, y);
	if ((g->player_anim == 0 || g->player_anim == 2)
		&& g->count_c < g->count_exit)
		mlx_put_image_to_window(g->mlx, g->win, g->textures[6], x, y);
	if (g->player_anim == 1 && g->count_c < g->count_exit)
		mlx_put_image_to_window(g->mlx, g->win, g->textures[7], x, y);
}

static void	put_image(t_game *g, int x, int y)
{
	if (g->map[g->row][g->col] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[0], x, y);
	else if (g->map[g->row][g->col] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[1], x, y);
	else if (g->map[g->row][g->col] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[2], x, y);
	else if (g->map[g->row][g->col] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[3], x, y);
	else if (g->map[g->row][g->col] == 'N')
		mlx_put_image_to_window(g->mlx, g->win, g->textures[8], x, y);
	else if (g->map[g->row][g->col] == 'P')
		anima_player(g, x, y);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	g->row = 0;
	if (g->player_anim == 2)
		g->player_anim = 2;
	else if (g->player_anim == 1)
		g->player_anim = 1;
	else
		g->player_anim = 0;
	move_enemy(g);
	while (g->map[g->row])
	{
		g->col = 0;
		while (g->map[g->row][g->col])
		{
			x = g->col * 50;
			y = g->row * 50;
			put_image(g, x, y);
			g->col++;
		}
		g->row++;
	}
}
