/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:53:22 by achemlal          #+#    #+#             */
/*   Updated: 2025/01/07 18:03:57 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_dimensions(t_game *g)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (g->map[row])
	{
		col = 0;
		while (g->map[row][col])
		{
			col++;
		}
		row++;
	}
	g->ww = col * 50;
	g->wh = row * 50;
}

static void	load_texture(t_game *g, int index, char *f)
{
	g->textures[index] = mlx_xpm_file_to_image(g->mlx, f, &g->iw, &g->ih);
	if (!g->textures[index])
		exit_window(g);
}

void	load_img(t_game *g)
{
	load_texture(g, 0, "./textures/wall.xpm");
	load_texture(g, 1, "./textures/route.xpm");
	load_texture(g, 2, "./textures/nud.xpm");
	load_texture(g, 3, "./textures/exit.xpm");
	load_texture(g, 4, "./textures/player.xpm");
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	g->row = 0;
	while (g->map[g->row])
	{
		g->col = 0;
		while (g->map[g->row][g->col])
		{
			x = g->col * 50;
			y = g->row * 50;
			if (g->map[g->row][g->col] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[0], x, y);
			else if (g->map[g->row][g->col] == '0')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[1], x, y);
			else if (g->map[g->row][g->col] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[2], x, y);
			else if (g->map[g->row][g->col] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[3], x, y);
			else if (g->map[g->row][g->col] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->textures[4], x, y);
			g->col++;
		}
		g->row++;
	}
}
